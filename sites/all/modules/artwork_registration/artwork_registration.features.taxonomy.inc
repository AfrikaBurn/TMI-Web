<?php
/**
 * @file
 * artwork_registration.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function artwork_registration_taxonomy_default_vocabularies() {
  return array(
    'project_size' => array(
      'name' => 'Project Size',
      'machine_name' => 'project_size',
      'description' => 'In terms of size, how would you classify your project?',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
