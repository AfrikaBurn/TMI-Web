<?php

/**
 * @file
 * Contains the MathfieldMathExpr class.
 */

ctools_include('math-expr');

/**
 * Evalueate a mathfield expression.
 */
class MathfieldMathExpr extends ctools_math_expr {
  /**
   * Handle errors gracefully.
   *
   * @throws MathfieldException
   */
  public function trigger($msg) {
    $this->last_error = $msg;
    if (!$this->suppress_errors) {
      throw new MathfieldException($msg);
    }
    return FALSE;
  }

}

/**
 * Error handler for mathfield expressions.
 */
class MathfieldException extends Exception {}
