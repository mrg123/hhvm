/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#pragma once

#include "hphp/runtime/vm/call-flags.h"
#include "hphp/runtime/vm/jit/types.h"

namespace HPHP {

struct ActRec;

namespace jit {

/*
 * Main entry point for the translator from the bytecode interpreter.  It
 * operates on behalf of a given nested invocation of the intepreter (calling
 * back into it as necessary for blocks that need to be interpreted).
 */
void enterTC(TCA start);

/*
 * The version of enterTC() that enters TC at a prologue.
 */
void enterTCAtPrologue(CallFlags callFlags, TCA start, ActRec* calleeAR);

}}
