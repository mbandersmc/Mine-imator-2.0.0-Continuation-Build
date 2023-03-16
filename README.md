# Mine-imator

<p align="center">
  <img src="https://www.mineimatorforums.com/uploads/monthly_2021_08/image.png.4699187f1f02be8222a5bf5100c1738f.png" width=800/>
  <br/>
  <br/>
  <img src="https://www.mineimatorforums.com/uploads/monthly_2023_03/336815532_programview.png.9212aa1f6d1bed63411408aa5e905ce0.png" width=800/>
</p>

Mine-imator is a 3D movie maker based on the sandbox game Minecraft, with over 8 million downloads since its launch in 2012. Version 2.0, the 10th anniversary update brings numerous additions including a new UI, new renderer, animation features, multiplatform support and 3D world importer.

Website and download: https://www.mineimator.com

The software is written using GameMaker Language and converted to a separate C++ environment using a custom built GML parser (CppGen). The final executable is built for Windows, Mac OS and Linux using the Qt framework, DirectX/OpenGL rendering and various other libraries.

<hr/>

Continuation Build Changelog since Mine-imator 2.0.0:
<i>(not tested outside of windows-x64)</i>

Additions:
<ul>
  <li>Added 'Speed / Pitch' setting for sounds in audio timelines.</li>
  <li>Added support for more unicode characters in Minecraft font.</li>
  <li>Splash screen now shows which Minecraft assets version is being loaded.</li>
  <li>Signs in imported worlds now have a 'text_scale' field (defined in .midata file).</li>
  <li>Added a ? somewhere.</li>
</ul>

Changes:
<ul>
  <li>Updated Minecraft assets to 1.19.4.</li>
  <li>Individual blocks for Iron Bars, Glass Panes, Fences, Walls, Chorus Plants, Fire, and Tripwire can now be fully customized in the workbench.</li>
  <li>Custom item slot interpolation is now floored instead of rounded.</li>
  <li>Updated credits.</li>
</ul>
  
Bugfixes:
<ul>
  <li>Fixed custom object fog color not being animatable with environment timelines.</li>
  <li>Fixed lens dirt glow not working.</li>
  <li>Fixed lens dirt not being affected by distort and chromatic aberration.</li>
  <li>Fixed sounds with extended end time not repeating in animation playback.</li>
  <li>Fixed "Randomize blocks" setting for blocks not being saved.</li>
  <li>Fixed minutes counter in timeline timer not resetting when an hour has passed.</li>
  <li>Fixed some minor issues with block texture animations.</li>
</ul>
