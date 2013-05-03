package com.kercar;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;

import com.kercar.osmandroid.OSMAndroid;

public class ChoixPointArrive extends Activity{
	
	//Attributs
	private OSMAndroid OSM;
	
	 @Override
	    protected void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	   
	        //ContentView
	        setContentView(R.layout.choix_point_arrive);
	        
	        OSM = (OSMAndroid)findViewById(R.id.OSM_choix_point);
	        
	    }

	    @Override
	    public boolean onCreateOptionsMenu(Menu menu) {
	        // Inflate the menu; this adds items to the action bar if it is present.
	        getMenuInflater().inflate(R.menu.activity_main, menu);
	        return true;
	    }
}