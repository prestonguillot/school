
/*Preston Guillot
 *Assignment 11 - Grasshopper Agent
 *Agent1 */
 
 import de.ikv.grasshopper.communication.GrasshopperAddress;
 import java.util.*;
 import javax.swing.JOptionPane;

 public class Agent1 extends de.ikv.grasshopper.agent.MobileAgent {
 	
 	final int SIZE = 10, LOWPORT = 7000, HIGHPORT = 7010;
 	String addresses[] = new String[SIZE], time = new String();
 	Vector agencies = new Vector();
 	int state, index, port;
 	
 	public void init(Object[] creationArgs) {
       	
       	int i = 0;
       	StringTokenizer input = new StringTokenizer(JOptionPane.showInputDialog("Enter up to 10 IPs, seperated by a space."));
       	
       	while((i < SIZE) && (input.hasMoreTokens())) {
       		
       		addresses[i] = input.nextToken();
       		i++;
       		
       		 
       	}
       	
       	while(i < SIZE) {
       		
       		addresses[i] = null;
       		i++;
       		
       	}
       	
       	state = 0;
       	index = 0;
       	port = LOWPORT;
       	getTime();	
    }
    
    public String getName() {
        return "PrestonGuillotAgent1";
    }
    
    public void getTime() {
    	
    	Calendar cal = new GregorianCalendar();
    	
    	time = Integer.toString(cal.get(Calendar.HOUR)) + ":" +
    		   Integer.toString(cal.get(Calendar.MINUTE)) + ":" +
    		   Integer.toString(cal.get(Calendar.SECOND)) + " ";
    	
    	if(cal.get(Calendar.AM_PM) == 1)
    		time += "PM";
    		
    	else
    		time += "AM";
    		 	
    }
    
    public void live() {
    	
    	switch(state) {
    		
    		case 0: //Agent is at Home.
    			
    			state = 1;
    			
    			while ((index < SIZE) && (addresses[index] != null)) {
    				
    				while(port <= HIGHPORT) {
    					
    					try {
    						move(new GrasshopperAddress("socket://" + addresses[index] + ":" + port + "/"));
    					}
    					catch (Exception x) {};
    					//agency not found
    					port += 2;
    				}
    				
    				index++;
    				port = LOWPORT;
    			}
    			
    			log("No active Agencies found.");
    			break;// Only reached when there are no more addresses.
    			
    		case 1: //Agent is at foriegn agency.
    		
    			agencies.add(addresses[index] + ":" + port);
    			log("Arrived at " + getInfo().getLocation() + ", from " + getInfo().getHome());
    			log("Time sent: " + time + ". Agency exists, moving to the next address.");
    			port += 2;
    			
    			while ((index < SIZE) && (addresses[index] != null)) {
    				
    				while(port <= HIGHPORT) {
    					
    					try {
    						move(new GrasshopperAddress("socket://" + addresses[index] + ":" + port + "/"));
    					}
    					catch (Exception x) {};
    					//agency not found
    					port += 2;
    				}
    				
    				index++;
    				port = LOWPORT;
    			}
    			
    			state = 2; //Reached when there are no more addresses.
    			try {
    				move(getInfo().getHome());
    			}
    			catch (Exception x) {
    				log("Failed to return home: ", x);
    			}
    			break;//Only reached if return trip fails.
    			
    		case 2: //Agent has returned Home.
    			
    			log("Agent sent at " + time);
    			log("Agencies found at: " + agencies.toString());
    	}
    	
    	log("Terminating execution.");
    }
 
    
}