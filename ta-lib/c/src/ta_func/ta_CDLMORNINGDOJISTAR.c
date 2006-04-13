/* TA-LIB Copyright (c) 1999-2006, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  AC       Angelo Ciceri
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  100304 AC   Creation           
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #include "TA-Lib-Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */    namespace TicTacTec { namespace TA { namespace Lib {
/* Generated */ #elif defined( _JAVA )
/* Generated */    #include "ta_defs.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::CDLMORNINGDOJISTAR_Lookback( double        optInPenetration )  /* From 0 to TA_REAL_MAX */
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int CDLMORNINGDOJISTAR_Lookback( double        optInPenetration )  /* From 0 to TA_REAL_MAX */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_CDLMORNINGDOJISTAR_Lookback( double        optInPenetration )  /* From 0 to TA_REAL_MAX */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */    if( optInPenetration == TA_REAL_DEFAULT )
/* Generated */       optInPenetration = 3.000000e-1;
/* Generated */    else if( (optInPenetration < 0.000000e+0) ||/* Generated */  (optInPenetration > 3.000000e+37) )
/* Generated */       return -1;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

   /* insert lookback code here. */
    UNUSED_VARIABLE(optInPenetration);
    return max( max( TA_CANDLEAVGPERIOD(TA_BodyDoji), TA_CANDLEAVGPERIOD(TA_BodyLong) ), 
                TA_CANDLEAVGPERIOD(TA_BodyShort) 
            ) + 2;
}

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/*
 * TA_CDLMORNINGDOJISTAR - Morning Doji Star
 * 
 * Input  = Open, High, Low, Close
 * Output = int
 * 
 * Optional Parameters
 * -------------------
 * optInPenetration:(From 0 to TA_REAL_MAX)
 *    Percentage of penetration of a candle within another candle
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::CDLMORNINGDOJISTAR( int    startIdx,
/* Generated */                                                       int    endIdx,
/* Generated */                                                       cli::array<double>^ inOpen,
/* Generated */                                                       cli::array<double>^ inHigh,
/* Generated */                                                       cli::array<double>^ inLow,
/* Generated */                                                       cli::array<double>^ inClose,
/* Generated */                                                       double        optInPenetration, /* From 0 to TA_REAL_MAX */
/* Generated */                                                       [Out]int%    outBegIdx,
/* Generated */                                                       [Out]int%    outNbElement,
/* Generated */                                                       cli::array<int>^  outInteger )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode CDLMORNINGDOJISTAR( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       double       inOpen[],
/* Generated */                                       double       inHigh[],
/* Generated */                                       double       inLow[],
/* Generated */                                       double       inClose[],
/* Generated */                                       double        optInPenetration, /* From 0 to TA_REAL_MAX */
/* Generated */                                       MInteger     outBegIdx,
/* Generated */                                       MInteger     outNbElement,
/* Generated */                                       int           outInteger[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_CDLMORNINGDOJISTAR( int    startIdx,
/* Generated */                                   int    endIdx,
/* Generated */                                   const double inOpen[],
/* Generated */                                   const double inHigh[],
/* Generated */                                   const double inLow[],
/* Generated */                                   const double inClose[],
/* Generated */                                   double        optInPenetration, /* From 0 to TA_REAL_MAX */
/* Generated */                                   int          *outBegIdx,
/* Generated */                                   int          *outNbElement,
/* Generated */                                   int           outInteger[] )
/* Generated */ #endif
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
    double BodyDojiPeriodTotal, BodyLongPeriodTotal, BodyShortPeriodTotal;
    int i, outIdx, BodyDojiTrailingIdx, BodyLongTrailingIdx, BodyShortTrailingIdx, lookbackTotal;

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    /* Verify required price component. */
/* Generated */    if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA)*/
/* Generated */    if( optInPenetration == TA_REAL_DEFAULT )
/* Generated */       optInPenetration = 3.000000e-1;
/* Generated */    else if( (optInPenetration < 0.000000e+0) ||/* Generated */  (optInPenetration > 3.000000e+37) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !outInteger )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    */

   lookbackTotal = LOOKBACK_CALL(CDLMORNINGDOJISTAR)(optInPenetration);

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      return NAMESPACE(TA_RetCode)TA_SUCCESS;
   }

   /* Do the calculation using tight loops. */
   /* Add-up the initial period, except for the last value. */
   BodyLongPeriodTotal = 0;
   BodyDojiPeriodTotal = 0;
   BodyShortPeriodTotal = 0;
   BodyLongTrailingIdx = startIdx -2 - TA_CANDLEAVGPERIOD(TA_BodyLong);
   BodyDojiTrailingIdx = startIdx -1 - TA_CANDLEAVGPERIOD(TA_BodyDoji);
   BodyShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_BodyShort);
   
   i = BodyLongTrailingIdx;
   while( i < startIdx-2 ) {
        BodyLongPeriodTotal += TA_CANDLERANGE( TA_BodyLong, i );
        i++;
   }
   i = BodyDojiTrailingIdx;
   while( i < startIdx-1 ) {
        BodyDojiPeriodTotal += TA_CANDLERANGE( TA_BodyDoji, i );
        i++;
   }
   i = BodyShortTrailingIdx;
   while( i < startIdx ) {
        BodyShortPeriodTotal += TA_CANDLERANGE( TA_BodyShort, i );
        i++;
   }
   i = startIdx;

   /* Proceed with the calculation for the requested range.
    * Must have:
    * - first candle: long black real body
    * - second candle: doji gapping down
    * - third candle: white real body that moves well within the first candle's real body
    * The meaning of "doji" and "long" is specified with TA_SetCandleSettings
    * The meaning of "moves well within" is specified with optInPenetration and "moves" should mean the real body should
    * not be short ("short" is specified with TA_SetCandleSettings) - Greg Morris wants it to be long, someone else want
    * it to be relatively long
    * outInteger is positive (1 to 100): morning doji star is always bullish;
    * the user should consider that a morning star is significant when it appears in a downtrend, 
    * while this function does not consider the trend
    */
   outIdx = 0;
   do
   {
        if( TA_REALBODY(i-2) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal, i-2 ) &&         // 1st: long
            TA_CANDLECOLOR(i-2) == -1 &&                                                            //           black
            TA_REALBODY(i-1) <= TA_CANDLEAVERAGE( TA_BodyDoji, BodyDojiPeriodTotal, i-1 ) &&        // 2nd: doji
            TA_REALBODYGAPDOWN(i-1,i-2) &&                                                          //           gapping down
            TA_REALBODY(i) > TA_CANDLEAVERAGE( TA_BodyShort, BodyShortPeriodTotal, i ) &&           // 3rd: longer than short
            TA_CANDLECOLOR(i) == 1 &&                                                               //          white real body
            inClose[i] > inClose[i-2] + TA_REALBODY(i-2) * optInPenetration                         //               closing well within 1st rb
          )
            outInteger[outIdx++] = 100;
        else
            outInteger[outIdx++] = 0;
        /* add the current range and subtract the first range: this is done after the pattern recognition 
         * when avgPeriod is not 0, that means "compare with the previous candles" (it excludes the current candle)
         */
        BodyLongPeriodTotal += TA_CANDLERANGE( TA_BodyLong, i-2 ) - TA_CANDLERANGE( TA_BodyLong, BodyLongTrailingIdx );
        BodyDojiPeriodTotal += TA_CANDLERANGE( TA_BodyDoji, i-1 ) - TA_CANDLERANGE( TA_BodyDoji, BodyDojiTrailingIdx );
        BodyShortPeriodTotal += TA_CANDLERANGE( TA_BodyShort, i ) - TA_CANDLERANGE( TA_BodyShort, BodyShortTrailingIdx );
        i++; 
        BodyLongTrailingIdx++;
        BodyDojiTrailingIdx++;
        BodyShortTrailingIdx++;
   } while( i <= endIdx );

   /* All done. Indicate the output limits and return. */
   VALUE_HANDLE_DEREF(outNbElement) = outIdx;
   VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;

   return NAMESPACE(TA_RetCode)TA_SUCCESS;
}

/**** START GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED ) && !defined( _JAVA )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::CDLMORNINGDOJISTAR( int    startIdx,
/* Generated */                                                       int    endIdx,
/* Generated */                                                       cli::array<float>^ inOpen,
/* Generated */                                                       cli::array<float>^ inHigh,
/* Generated */                                                       cli::array<float>^ inLow,
/* Generated */                                                       cli::array<float>^ inClose,
/* Generated */                                                       double        optInPenetration, /* From 0 to TA_REAL_MAX */
/* Generated */                                                       [Out]int%    outBegIdx,
/* Generated */                                                       [Out]int%    outNbElement,
/* Generated */                                                       cli::array<int>^  outInteger )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode CDLMORNINGDOJISTAR( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       float        inOpen[],
/* Generated */                                       float        inHigh[],
/* Generated */                                       float        inLow[],
/* Generated */                                       float        inClose[],
/* Generated */                                       double        optInPenetration, /* From 0 to TA_REAL_MAX */
/* Generated */                                       MInteger     outBegIdx,
/* Generated */                                       MInteger     outNbElement,
/* Generated */                                       int           outInteger[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_CDLMORNINGDOJISTAR( int    startIdx,
/* Generated */                                     int    endIdx,
/* Generated */                                     const float  inOpen[],
/* Generated */                                     const float  inHigh[],
/* Generated */                                     const float  inLow[],
/* Generated */                                     const float  inClose[],
/* Generated */                                     double        optInPenetration, /* From 0 to TA_REAL_MAX */
/* Generated */                                     int          *outBegIdx,
/* Generated */                                     int          *outNbElement,
/* Generated */                                     int           outInteger[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */     double BodyDojiPeriodTotal, BodyLongPeriodTotal, BodyShortPeriodTotal;
/* Generated */     int i, outIdx, BodyDojiTrailingIdx, BodyLongTrailingIdx, BodyShortTrailingIdx, lookbackTotal;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */     if( optInPenetration == TA_REAL_DEFAULT )
/* Generated */        optInPenetration = 3.000000e-1;
/* Generated */     else if( (optInPenetration < 0.000000e+0) ||  (optInPenetration > 3.000000e+37) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !outInteger )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    lookbackTotal = LOOKBACK_CALL(CDLMORNINGDOJISTAR)(optInPenetration);
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */    }
/* Generated */    BodyLongPeriodTotal = 0;
/* Generated */    BodyDojiPeriodTotal = 0;
/* Generated */    BodyShortPeriodTotal = 0;
/* Generated */    BodyLongTrailingIdx = startIdx -2 - TA_CANDLEAVGPERIOD(TA_BodyLong);
/* Generated */    BodyDojiTrailingIdx = startIdx -1 - TA_CANDLEAVGPERIOD(TA_BodyDoji);
/* Generated */    BodyShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_BodyShort);
/* Generated */    i = BodyLongTrailingIdx;
/* Generated */    while( i < startIdx-2 ) {
/* Generated */         BodyLongPeriodTotal += TA_CANDLERANGE( TA_BodyLong, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = BodyDojiTrailingIdx;
/* Generated */    while( i < startIdx-1 ) {
/* Generated */         BodyDojiPeriodTotal += TA_CANDLERANGE( TA_BodyDoji, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = BodyShortTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         BodyShortPeriodTotal += TA_CANDLERANGE( TA_BodyShort, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = startIdx;
/* Generated */    outIdx = 0;
/* Generated */    do
/* Generated */    {
/* Generated */         if( TA_REALBODY(i-2) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal, i-2 ) &&         // 1st: long
/* Generated */             TA_CANDLECOLOR(i-2) == -1 &&                                                            //           black
/* Generated */             TA_REALBODY(i-1) <= TA_CANDLEAVERAGE( TA_BodyDoji, BodyDojiPeriodTotal, i-1 ) &&        // 2nd: doji
/* Generated */             TA_REALBODYGAPDOWN(i-1,i-2) &&                                                          //           gapping down
/* Generated */             TA_REALBODY(i) > TA_CANDLEAVERAGE( TA_BodyShort, BodyShortPeriodTotal, i ) &&           // 3rd: longer than short
/* Generated */             TA_CANDLECOLOR(i) == 1 &&                                                               //          white real body
/* Generated */             inClose[i] > inClose[i-2] + TA_REALBODY(i-2) * optInPenetration                         //               closing well within 1st rb
/* Generated */           )
/* Generated */             outInteger[outIdx++] = 100;
/* Generated */         else
/* Generated */             outInteger[outIdx++] = 0;
/* Generated */         BodyLongPeriodTotal += TA_CANDLERANGE( TA_BodyLong, i-2 ) - TA_CANDLERANGE( TA_BodyLong, BodyLongTrailingIdx );
/* Generated */         BodyDojiPeriodTotal += TA_CANDLERANGE( TA_BodyDoji, i-1 ) - TA_CANDLERANGE( TA_BodyDoji, BodyDojiTrailingIdx );
/* Generated */         BodyShortPeriodTotal += TA_CANDLERANGE( TA_BodyShort, i ) - TA_CANDLERANGE( TA_BodyShort, BodyShortTrailingIdx );
/* Generated */         i++; 
/* Generated */         BodyLongTrailingIdx++;
/* Generated */         BodyDojiTrailingIdx++;
/* Generated */         BodyShortTrailingIdx++;
/* Generated */    } while( i <= endIdx );
/* Generated */    VALUE_HANDLE_DEREF(outNbElement) = outIdx;
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;
/* Generated */    return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }}} // Close namespace TicTacTec.TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/

