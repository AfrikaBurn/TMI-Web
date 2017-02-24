<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns='http://www.w3.org/1999/xhtml' xml:lang='en' lang='en'>
<head>
<title>sandbox-ssekono-2028575 - For more information about this repository, visit the project page at http://drupal.org/sandbox/ssekono/2028575</title>
<meta name='generator' content='cgit v0.12'/>
<meta name='robots' content='index, nofollow'/>
<link rel='stylesheet' type='text/css' href='/cgit-data/cgit.css'/>
<link rel='shortcut icon' href='/favicon.ico'/>
<link rel='alternate' title='Atom feed' href='http://cgit.drupalcode.org/sandbox-ssekono-2028575/atom/charts_graphs_d3.class.inc?h=7.x-1.x' type='application/atom+xml'/>
<link rel='vcs-git' href='git://git.drupal.org/sandbox/ssekono/2028575.git' title='sandbox-ssekono-2028575 Git repository'/>
</head>
<body>
<div id='cgit'><table id='header'>
<tr>
<td class='logo' rowspan='2'><a href='/'><img src='/cgit-data/logo.png' alt='cgit logo'/></a></td>
<td class='main'><a href='/'>index</a> : <a title='sandbox-ssekono-2028575' href='/sandbox-ssekono-2028575/'>sandbox-ssekono-2028575</a></td><td class='form'><form method='get' action=''>
<select name='h' onchange='this.form.submit();'>
<option value='7.x-1.x' selected='selected'>7.x-1.x</option>
</select> <input type='submit' name='' value='switch'/></form></td></tr>
<tr><td class='sub'>For more information about this repository, visit the project page at http://drupal.org/sandbox/ssekono/2028575</td><td class='sub right'>Drupal Git User (LDAP)</td></tr></table>
<table class='tabs'><tr><td>
<a href='/sandbox-ssekono-2028575/'>summary</a><a href='/sandbox-ssekono-2028575/refs/'>refs</a><a href='/sandbox-ssekono-2028575/log/charts_graphs_d3.class.inc'>log</a><a class='active' href='/sandbox-ssekono-2028575/tree/charts_graphs_d3.class.inc'>tree</a><a href='/sandbox-ssekono-2028575/commit/charts_graphs_d3.class.inc'>commit</a><a href='/sandbox-ssekono-2028575/diff/charts_graphs_d3.class.inc'>diff</a><a href='/sandbox-ssekono-2028575/stats/charts_graphs_d3.class.inc'>stats</a></td><td class='form'><form class='right' method='get' action='/sandbox-ssekono-2028575/log/charts_graphs_d3.class.inc'>
<select name='qt'>
<option value='grep'>log msg</option>
<option value='author'>author</option>
<option value='committer'>committer</option>
<option value='range'>range</option>
</select>
<input class='txt' type='text' size='10' name='q' value=''/>
<input type='submit' value='search'/>
</form>
</td></tr></table>
<div class='path'>path: <a href='/sandbox-ssekono-2028575/tree/'>root</a>/<a href='/sandbox-ssekono-2028575/tree/charts_graphs_d3.class.inc'>charts_graphs_d3.class.inc</a></div><div class='content'>blob: 69794acdcddd80ec6ddd7d14cb2e10863fa0d79e (<a href='/sandbox-ssekono-2028575/plain/charts_graphs_d3.class.inc'>plain</a>)
<table summary='blob content' class='blob'>
<tr><td class='linenumbers'><pre><a id='n1' href='#n1'>1</a>
<a id='n2' href='#n2'>2</a>
<a id='n3' href='#n3'>3</a>
<a id='n4' href='#n4'>4</a>
<a id='n5' href='#n5'>5</a>
<a id='n6' href='#n6'>6</a>
<a id='n7' href='#n7'>7</a>
<a id='n8' href='#n8'>8</a>
<a id='n9' href='#n9'>9</a>
<a id='n10' href='#n10'>10</a>
<a id='n11' href='#n11'>11</a>
<a id='n12' href='#n12'>12</a>
<a id='n13' href='#n13'>13</a>
<a id='n14' href='#n14'>14</a>
<a id='n15' href='#n15'>15</a>
<a id='n16' href='#n16'>16</a>
<a id='n17' href='#n17'>17</a>
<a id='n18' href='#n18'>18</a>
<a id='n19' href='#n19'>19</a>
<a id='n20' href='#n20'>20</a>
<a id='n21' href='#n21'>21</a>
<a id='n22' href='#n22'>22</a>
<a id='n23' href='#n23'>23</a>
<a id='n24' href='#n24'>24</a>
<a id='n25' href='#n25'>25</a>
<a id='n26' href='#n26'>26</a>
<a id='n27' href='#n27'>27</a>
<a id='n28' href='#n28'>28</a>
<a id='n29' href='#n29'>29</a>
<a id='n30' href='#n30'>30</a>
<a id='n31' href='#n31'>31</a>
<a id='n32' href='#n32'>32</a>
<a id='n33' href='#n33'>33</a>
<a id='n34' href='#n34'>34</a>
<a id='n35' href='#n35'>35</a>
<a id='n36' href='#n36'>36</a>
<a id='n37' href='#n37'>37</a>
<a id='n38' href='#n38'>38</a>
<a id='n39' href='#n39'>39</a>
<a id='n40' href='#n40'>40</a>
<a id='n41' href='#n41'>41</a>
<a id='n42' href='#n42'>42</a>
<a id='n43' href='#n43'>43</a>
<a id='n44' href='#n44'>44</a>
<a id='n45' href='#n45'>45</a>
<a id='n46' href='#n46'>46</a>
<a id='n47' href='#n47'>47</a>
<a id='n48' href='#n48'>48</a>
<a id='n49' href='#n49'>49</a>
<a id='n50' href='#n50'>50</a>
<a id='n51' href='#n51'>51</a>
<a id='n52' href='#n52'>52</a>
<a id='n53' href='#n53'>53</a>
<a id='n54' href='#n54'>54</a>
<a id='n55' href='#n55'>55</a>
<a id='n56' href='#n56'>56</a>
<a id='n57' href='#n57'>57</a>
<a id='n58' href='#n58'>58</a>
<a id='n59' href='#n59'>59</a>
<a id='n60' href='#n60'>60</a>
<a id='n61' href='#n61'>61</a>
<a id='n62' href='#n62'>62</a>
<a id='n63' href='#n63'>63</a>
<a id='n64' href='#n64'>64</a>
<a id='n65' href='#n65'>65</a>
<a id='n66' href='#n66'>66</a>
<a id='n67' href='#n67'>67</a>
<a id='n68' href='#n68'>68</a>
<a id='n69' href='#n69'>69</a>
<a id='n70' href='#n70'>70</a>
<a id='n71' href='#n71'>71</a>
<a id='n72' href='#n72'>72</a>
<a id='n73' href='#n73'>73</a>
<a id='n74' href='#n74'>74</a>
<a id='n75' href='#n75'>75</a>
<a id='n76' href='#n76'>76</a>
<a id='n77' href='#n77'>77</a>
<a id='n78' href='#n78'>78</a>
<a id='n79' href='#n79'>79</a>
<a id='n80' href='#n80'>80</a>
<a id='n81' href='#n81'>81</a>
<a id='n82' href='#n82'>82</a>
<a id='n83' href='#n83'>83</a>
<a id='n84' href='#n84'>84</a>
<a id='n85' href='#n85'>85</a>
<a id='n86' href='#n86'>86</a>
<a id='n87' href='#n87'>87</a>
<a id='n88' href='#n88'>88</a>
<a id='n89' href='#n89'>89</a>
<a id='n90' href='#n90'>90</a>
<a id='n91' href='#n91'>91</a>
<a id='n92' href='#n92'>92</a>
<a id='n93' href='#n93'>93</a>
<a id='n94' href='#n94'>94</a>
<a id='n95' href='#n95'>95</a>
<a id='n96' href='#n96'>96</a>
<a id='n97' href='#n97'>97</a>
<a id='n98' href='#n98'>98</a>
<a id='n99' href='#n99'>99</a>
<a id='n100' href='#n100'>100</a>
<a id='n101' href='#n101'>101</a>
<a id='n102' href='#n102'>102</a>
<a id='n103' href='#n103'>103</a>
<a id='n104' href='#n104'>104</a>
<a id='n105' href='#n105'>105</a>
<a id='n106' href='#n106'>106</a>
<a id='n107' href='#n107'>107</a>
<a id='n108' href='#n108'>108</a>
<a id='n109' href='#n109'>109</a>
<a id='n110' href='#n110'>110</a>
<a id='n111' href='#n111'>111</a>
<a id='n112' href='#n112'>112</a>
<a id='n113' href='#n113'>113</a>
</pre></td>
<td class='lines'><pre><code><style>.highlight .hll { background-color: #ffffcc }
.highlight  { background: #ffffff; }
.highlight .c { color: #888888 } /* Comment */
.highlight .err { color: #a61717; background-color: #e3d2d2 } /* Error */
.highlight .k { color: #008800; font-weight: bold } /* Keyword */
.highlight .cm { color: #888888 } /* Comment.Multiline */
.highlight .cp { color: #cc0000; font-weight: bold } /* Comment.Preproc */
.highlight .c1 { color: #888888 } /* Comment.Single */
.highlight .cs { color: #cc0000; font-weight: bold; background-color: #fff0f0 } /* Comment.Special */
.highlight .gd { color: #000000; background-color: #ffdddd } /* Generic.Deleted */
.highlight .ge { font-style: italic } /* Generic.Emph */
.highlight .gr { color: #aa0000 } /* Generic.Error */
.highlight .gh { color: #303030 } /* Generic.Heading */
.highlight .gi { color: #000000; background-color: #ddffdd } /* Generic.Inserted */
.highlight .go { color: #888888 } /* Generic.Output */
.highlight .gp { color: #555555 } /* Generic.Prompt */
.highlight .gs { font-weight: bold } /* Generic.Strong */
.highlight .gu { color: #606060 } /* Generic.Subheading */
.highlight .gt { color: #aa0000 } /* Generic.Traceback */
.highlight .kc { color: #008800; font-weight: bold } /* Keyword.Constant */
.highlight .kd { color: #008800; font-weight: bold } /* Keyword.Declaration */
.highlight .kn { color: #008800; font-weight: bold } /* Keyword.Namespace */
.highlight .kp { color: #008800 } /* Keyword.Pseudo */
.highlight .kr { color: #008800; font-weight: bold } /* Keyword.Reserved */
.highlight .kt { color: #888888; font-weight: bold } /* Keyword.Type */
.highlight .m { color: #0000DD; font-weight: bold } /* Literal.Number */
.highlight .s { color: #dd2200; background-color: #fff0f0 } /* Literal.String */
.highlight .na { color: #336699 } /* Name.Attribute */
.highlight .nb { color: #003388 } /* Name.Builtin */
.highlight .nc { color: #bb0066; font-weight: bold } /* Name.Class */
.highlight .no { color: #003366; font-weight: bold } /* Name.Constant */
.highlight .nd { color: #555555 } /* Name.Decorator */
.highlight .ne { color: #bb0066; font-weight: bold } /* Name.Exception */
.highlight .nf { color: #0066bb; font-weight: bold } /* Name.Function */
.highlight .nl { color: #336699; font-style: italic } /* Name.Label */
.highlight .nn { color: #bb0066; font-weight: bold } /* Name.Namespace */
.highlight .py { color: #336699; font-weight: bold } /* Name.Property */
.highlight .nt { color: #bb0066; font-weight: bold } /* Name.Tag */
.highlight .nv { color: #336699 } /* Name.Variable */
.highlight .ow { color: #008800 } /* Operator.Word */
.highlight .w { color: #bbbbbb } /* Text.Whitespace */
.highlight .mf { color: #0000DD; font-weight: bold } /* Literal.Number.Float */
.highlight .mh { color: #0000DD; font-weight: bold } /* Literal.Number.Hex */
.highlight .mi { color: #0000DD; font-weight: bold } /* Literal.Number.Integer */
.highlight .mo { color: #0000DD; font-weight: bold } /* Literal.Number.Oct */
.highlight .sb { color: #dd2200; background-color: #fff0f0 } /* Literal.String.Backtick */
.highlight .sc { color: #dd2200; background-color: #fff0f0 } /* Literal.String.Char */
.highlight .sd { color: #dd2200; background-color: #fff0f0 } /* Literal.String.Doc */
.highlight .s2 { color: #dd2200; background-color: #fff0f0 } /* Literal.String.Double */
.highlight .se { color: #0044dd; background-color: #fff0f0 } /* Literal.String.Escape */
.highlight .sh { color: #dd2200; background-color: #fff0f0 } /* Literal.String.Heredoc */
.highlight .si { color: #3333bb; background-color: #fff0f0 } /* Literal.String.Interpol */
.highlight .sx { color: #22bb22; background-color: #f0fff0 } /* Literal.String.Other */
.highlight .sr { color: #008800; background-color: #fff0ff } /* Literal.String.Regex */
.highlight .s1 { color: #dd2200; background-color: #fff0f0 } /* Literal.String.Single */
.highlight .ss { color: #aa6600; background-color: #fff0f0 } /* Literal.String.Symbol */
.highlight .bp { color: #003388 } /* Name.Builtin.Pseudo */
.highlight .vc { color: #336699 } /* Name.Variable.Class */
.highlight .vg { color: #dd7700 } /* Name.Variable.Global */
.highlight .vi { color: #3333bb } /* Name.Variable.Instance */
.highlight .il { color: #0000DD; font-weight: bold } /* Literal.Number.Integer.Long */</style><div class="highlight"><pre><span class="cp">&lt;?php</span>
<span class="sd">/**</span>
<span class="sd"> * @file</span>
<span class="sd"> * Implementation of abstract class ChartsGraphsCanvas for D3 library.</span>
<span class="sd"> */</span>

<span class="sd">/**</span>
<span class="sd"> * Implementation of abstract class ChartsGraphsCanvas for D3 library.</span>
<span class="sd"> */</span>
<span class="k">class</span> <span class="nc">ChartsGraphsD3</span> <span class="k">extends</span> <span class="nx">ChartsGraphsCanvas</span> <span class="p">{</span>

  <span class="cm">/*</span>
<span class="cm">   * Set some defaults</span>
<span class="cm">   */</span>
  <span class="k">public</span> <span class="nv">$width</span> <span class="o">=</span> <span class="m">700</span><span class="p">;</span>
  <span class="k">public</span> <span class="nv">$height</span> <span class="o">=</span> <span class="m">400</span><span class="p">;</span>
  <span class="k">public</span> <span class="nv">$title</span> <span class="o">=</span> <span class="s1">&#39;&#39;</span><span class="p">;</span>
  <span class="k">public</span> <span class="nv">$series_colours</span> <span class="o">=</span> <span class="k">array</span><span class="p">(</span><span class="s1">&#39;blue&#39;</span><span class="p">,</span> <span class="s1">&#39;red&#39;</span><span class="p">,</span> <span class="s1">&#39;orange&#39;</span><span class="p">,</span> <span class="s1">&#39;green&#39;</span><span class="p">,</span> <span class="s1">&#39;purple&#39;</span><span class="p">);</span>
  <span class="k">public</span> <span class="nv">$showlegend</span> <span class="o">=</span> <span class="m">1</span><span class="p">;</span>
  <span class="k">public</span> <span class="nv">$colour</span> <span class="o">=</span> <span class="s1">&#39;white&#39;</span><span class="p">;</span>

  <span class="sd">/**</span>
<span class="sd">   * Function that renders data.</span>
<span class="sd">   */</span>
  <span class="k">public</span> <span class="k">function</span> <span class="nf">get_chart</span><span class="p">()</span> <span class="p">{</span>

    <span class="cm">/*</span>
<span class="cm">    * Based on the type of graph, get a default style</span>
<span class="cm">    * and set some additional options if we need them</span>
<span class="cm">    */</span>
    <span class="nv">$legend</span> <span class="o">=</span> <span class="k">array</span><span class="p">();</span>
    <span class="k">switch</span> <span class="p">(</span><span class="nv">$this</span><span class="o">-&gt;</span><span class="na">type</span><span class="p">)</span> <span class="p">{</span>

      <span class="k">case</span> <span class="s1">&#39;LineGraph&#39;</span><span class="o">:</span>
      <span class="k">case</span> <span class="s1">&#39;ColumnChart&#39;</span><span class="o">:</span>
      <span class="k">case</span> <span class="s1">&#39;BarChart&#39;</span><span class="o">:</span>
        <span class="nv">$legend</span> <span class="o">=</span> <span class="nb">array_keys</span><span class="p">(</span><span class="nv">$this</span><span class="o">-&gt;</span><span class="na">series</span><span class="p">);</span>
        <span class="nv">$series</span> <span class="o">=</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">series</span><span class="p">;</span>
        <span class="nv">$data</span> <span class="o">=</span> <span class="k">Array</span><span class="p">();</span>
        <span class="nv">$rows</span> <span class="o">=</span> <span class="k">Array</span><span class="p">();</span>
        <span class="k">foreach</span> <span class="p">(</span><span class="nv">$this</span><span class="o">-&gt;</span><span class="na">series</span> <span class="k">as</span> <span class="nv">$serie</span><span class="p">)</span> <span class="p">{</span>
          <span class="k">foreach</span> <span class="p">(</span><span class="nv">$serie</span> <span class="k">as</span> <span class="nv">$key</span> <span class="o">=&gt;</span> <span class="nv">$element</span><span class="p">)</span> <span class="p">{</span>
            <span class="nv">$data</span><span class="p">[</span><span class="nv">$key</span><span class="p">][]</span> <span class="o">=</span> <span class="nv">$element</span><span class="p">;</span>
          <span class="p">}</span>
        <span class="p">}</span>

        <span class="k">foreach</span> <span class="p">(</span><span class="nv">$this</span><span class="o">-&gt;</span><span class="na">x_labels</span> <span class="k">as</span> <span class="nv">$key</span> <span class="o">=&gt;</span> <span class="nv">$label</span><span class="p">)</span> <span class="p">{</span>
          <span class="nv">$rows</span><span class="p">[]</span> <span class="o">=</span> <span class="nb">array_merge</span><span class="p">(</span><span class="k">array</span><span class="p">(</span><span class="nv">$label</span><span class="p">),</span> <span class="nb">array_values</span><span class="p">(</span><span class="nv">$data</span><span class="p">[</span><span class="nv">$key</span><span class="p">]));</span>
        <span class="p">}</span>

      <span class="k">break</span><span class="p">;</span>

      <span class="k">case</span> <span class="s1">&#39;PieChart&#39;</span><span class="o">:</span>
      <span class="k">case</span> <span class="s1">&#39;DonutChart&#39;</span><span class="o">:</span>

        <span class="nv">$pieserie</span> <span class="o">=</span> <span class="nb">reset</span><span class="p">(</span><span class="nv">$this</span><span class="o">-&gt;</span><span class="na">series</span><span class="p">);</span>
        <span class="nv">$i</span> <span class="o">=</span> <span class="m">0</span><span class="p">;</span>
        <span class="k">foreach</span> <span class="p">(</span><span class="nv">$pieserie</span> <span class="k">as</span> <span class="nv">$serie</span><span class="p">)</span> <span class="p">{</span>
          <span class="nv">$rows</span><span class="p">[]</span> <span class="o">=</span> <span class="nb">array_merge</span><span class="p">(</span><span class="k">array</span><span class="p">(</span><span class="nv">$this</span><span class="o">-&gt;</span><span class="na">x_labels</span><span class="p">[</span><span class="nv">$i</span><span class="p">],</span> <span class="nv">$serie</span><span class="p">));</span>
          <span class="nv">$i</span><span class="o">++</span><span class="p">;</span>
        <span class="p">}</span>

        <span class="k">if</span> <span class="p">(</span><span class="nb">isset</span><span class="p">(</span><span class="nv">$legend</span><span class="p">))</span> <span class="p">{</span>
          <span class="nv">$chart</span><span class="p">[</span><span class="s1">&#39;legend&#39;</span><span class="p">]</span> <span class="o">=</span> <span class="nv">$legend</span><span class="p">;</span>
        <span class="p">}</span>

        <span class="k">break</span><span class="p">;</span>

      <span class="k">case</span> <span class="s1">&#39;BubbleChart&#39;</span><span class="o">:</span>

        <span class="nv">$bubbleserie</span> <span class="o">=</span> <span class="nb">reset</span><span class="p">(</span><span class="nv">$this</span><span class="o">-&gt;</span><span class="na">series</span><span class="p">);</span>
        <span class="nv">$i</span> <span class="o">=</span> <span class="m">0</span><span class="p">;</span>
        <span class="k">foreach</span> <span class="p">(</span><span class="nv">$bubbleserie</span> <span class="k">as</span> <span class="nv">$serie</span><span class="p">)</span> <span class="p">{</span>
          <span class="nv">$child</span><span class="p">[]</span> <span class="o">=</span> <span class="nb">array_merge</span><span class="p">(</span><span class="k">array</span><span class="p">(</span><span class="s1">&#39;name&#39;</span> <span class="o">=&gt;</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">x_labels</span><span class="p">[</span><span class="nv">$i</span><span class="p">],</span><span class="s1">&#39;size&#39;</span> <span class="o">=&gt;</span> <span class="nv">$serie</span><span class="p">));</span>
          <span class="nv">$i</span><span class="o">++</span><span class="p">;</span>
        <span class="p">}</span>

        <span class="nv">$jsonArray</span> <span class="o">=</span> <span class="k">array</span><span class="p">(</span><span class="s1">&#39;name&#39;</span> <span class="o">=&gt;</span> <span class="s1">&#39;Bubbles&#39;</span><span class="p">,</span> <span class="s1">&#39;children&#39;</span> <span class="o">=&gt;</span> <span class="nv">$child</span><span class="p">);</span>

        <span class="nv">$rows</span> <span class="o">=</span> <span class="nx">drupal_json_encode</span><span class="p">(</span><span class="nv">$jsonArray</span><span class="p">);</span>

        <span class="k">if</span> <span class="p">(</span><span class="nb">isset</span><span class="p">(</span><span class="nv">$legend</span><span class="p">))</span> <span class="p">{</span>
          <span class="nv">$chart</span><span class="p">[</span><span class="s1">&#39;legend&#39;</span><span class="p">]</span> <span class="o">=</span> <span class="nv">$legend</span><span class="p">;</span>
        <span class="p">}</span>

      <span class="k">break</span><span class="p">;</span>

      <span class="k">default</span><span class="o">:</span>
        <span class="nv">$element</span> <span class="o">=</span> <span class="k">array</span><span class="p">(</span>
          <span class="s2">&quot;#markup&quot;</span> <span class="o">=&gt;</span> <span class="nx">t</span><span class="p">(</span><span class="s2">&quot;Chart type @name is not supported.&quot;</span><span class="p">,</span> <span class="k">array</span><span class="p">(</span><span class="s1">&#39;@name&#39;</span> <span class="o">=&gt;</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">type</span><span class="p">)),</span>
        <span class="p">);</span>
        <span class="k">return</span> <span class="nv">$element</span><span class="p">;</span>
    <span class="p">}</span>

    <span class="nv">$chart</span> <span class="o">=</span> <span class="k">array</span><span class="p">(</span>
      <span class="s1">&#39;id&#39;</span> <span class="o">=&gt;</span> <span class="s1">&#39;chart-&#39;</span><span class="o">.</span><span class="nv">$this</span><span class="o">-&gt;</span><span class="na">unique_id</span><span class="p">,</span>
      <span class="s1">&#39;type&#39;</span> <span class="o">=&gt;</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">type</span><span class="p">,</span>
      <span class="s1">&#39;legend&#39;</span> <span class="o">=&gt;</span> <span class="nv">$legend</span><span class="p">,</span>
      <span class="s1">&#39;rows&#39;</span> <span class="o">=&gt;</span> <span class="nv">$rows</span><span class="p">,</span>
      <span class="s1">&#39;width&#39;</span> <span class="o">=&gt;</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">width</span><span class="p">,</span>
      <span class="s1">&#39;height&#39;</span> <span class="o">=&gt;</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">height</span><span class="p">,</span>
      <span class="s1">&#39;title&#39;</span> <span class="o">=&gt;</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">title</span><span class="p">,</span>
      <span class="s1">&#39;series_colours&#39;</span> <span class="o">=&gt;</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">series_colours</span><span class="p">,</span>
      <span class="s1">&#39;showlegend&#39;</span> <span class="o">=&gt;</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">showlegend</span><span class="p">,</span>
      <span class="s1">&#39;colour&#39;</span> <span class="o">=&gt;</span> <span class="nv">$this</span><span class="o">-&gt;</span><span class="na">colour</span><span class="p">,</span>
    <span class="p">);</span>

    <span class="nv">$element</span> <span class="o">=</span> <span class="k">array</span><span class="p">(</span>
      <span class="s2">&quot;#markup&quot;</span> <span class="o">=&gt;</span> <span class="nx">d3_draw</span><span class="p">(</span><span class="nv">$chart</span><span class="p">),</span>
    <span class="p">);</span>
    <span class="k">return</span> <span class="nv">$element</span><span class="p">;</span>
  <span class="p">}</span>
<span class="p">}</span>
</pre></div>
</code></pre></td></tr></table>
</div> <!-- class=content -->
<div class='footer'>generated by <a href='http://git.zx2c4.com/cgit/about/'>cgit v0.12</a> at 2017-02-12 13:11:15 (GMT)</div>
</div> <!-- id=cgit -->
</body>
</html>
