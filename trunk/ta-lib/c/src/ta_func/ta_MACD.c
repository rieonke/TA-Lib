/* TA-LIB Copyright (c) 1999-2003, Mario Fortier
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
 *  MF       Mario Fortier
 *  JPP      JP Pienaar (j.pienaar@mci.co.za)
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  112400 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *  080403 JPP  Fix #767653 for logic when swapping periods.
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #using <mscorlib.dll>
/* Generated */    #include "Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (TA_INTERNAL_ERROR)
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */    #include "ta_trace.h"
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
/* Generated */ int Core::MACD_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                        int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                        int           optInSignalPeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_MACD_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                     int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                     int           optInSignalPeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   /* The lookback is driven by the signal line output.
    *
    * (must also account for the initial data consume 
    *  by the slow period).
    */
   int tempInteger;

   /* Make sure slow is really slower than
    * the fast period! if not, swap...
    */
   if( optInSlowPeriod < optInFastPeriod )
   {
       /* swap */
       tempInteger       = optInSlowPeriod;
       optInSlowPeriod = optInFastPeriod;
       optInFastPeriod = tempInteger;
   }

   return   TA_EMA_Lookback( optInSlowPeriod   )
          + TA_EMA_Lookback( optInSignalPeriod );
}


/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_MACD - Moving Average Convergence/Divergence
 * 
 * Input  = double
 * Output = double, double, double
 * 
 * Optional Parameters
 * -------------------
 * optInFastPeriod:(From 2 to 100000)
 *    Number of period for the fast MA
 * 
 * optInSlowPeriod:(From 2 to 100000)
 *    Number of period for the slow MA
 * 
 * optInSignalPeriod:(From 1 to 100000)
 *    Smoothing for the signal line (nb of period)
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::MACD( int    startIdx,
/* Generated */                                   int    endIdx,
/* Generated */                                   double       inReal __gc [],
/* Generated */                                   int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                   int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                   int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                                   [OutAttribute]Int32 *outBegIdx,
/* Generated */                                   [OutAttribute]Int32 *outNbElement,
/* Generated */                                   double        outMACD __gc [],
/* Generated */                                   double        outMACDSignal __gc [],
/* Generated */                                   double        outMACDHist __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_MACD( int    startIdx,
/* Generated */                     int    endIdx,
/* Generated */                     const double inReal[],
/* Generated */                     int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                     int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                     int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                     int          *outBegIdx,
/* Generated */                     int          *outNbElement,
/* Generated */                     double        outMACD[],
/* Generated */                     double        outMACDSignal[],
/* Generated */                     double        outMACDHist[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    /* Validate the parameters. */
/* Generated */    if( !inReal ) return TA_BAD_PARAM;
/* Generated */    /* min/max are checked for optInFastPeriod. */
/* Generated */    if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInFastPeriod = 12;
/* Generated */    else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    /* min/max are checked for optInSlowPeriod. */
/* Generated */    if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSlowPeriod = 26;
/* Generated */    else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    /* min/max are checked for optInSignalPeriod. */
/* Generated */    if( (int)optInSignalPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSignalPeriod = 9;
/* Generated */    else if( ((int)optInSignalPeriod < 1) || ((int)optInSignalPeriod > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outMACD == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outMACDSignal == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outMACDHist == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */  

   return TA_PREFIX(INT_MACD)( startIdx, endIdx, inReal,
                               optInFastPeriod,
                               optInSlowPeriod,
                               optInSignalPeriod,
                               outBegIdx,
                               outNbElement,
                               outMACD,
                               outMACDSignal,
                               outMACDHist );
}

#if defined( _MANAGED )
enum Core::TA_RetCode Core::TA_INT_MACD( int    startIdx,
                                         int    endIdx,
                                         INPUT_TYPE inReal __gc [],
                                         int    optInFastPeriod, /* From 1 to 200, 0 is fix 12 */
                                         int    optInSlowPeriod, /* From 1 to 200, 0 is fix 26 */
                                         int    optInSignalPeriod_2, /* From 1 to 200 */
                                         [OutAttribute]Int32 *outBegIdx,
                                         [OutAttribute]Int32 *outNbElement,
                                         double outMACD __gc [],
                                         double outMACDSignal __gc [],
                                         double outMACDHist __gc [] )
#else
TA_RetCode TA_PREFIX(INT_MACD)( int    startIdx,
                                int    endIdx,
                                const INPUT_TYPE inReal[],
                                int    optInFastPeriod, /* From 1 to 200, 0 is fix 12 */
                                int    optInSlowPeriod, /* From 1 to 200, 0 is fix 26 */
                                int    optInSignalPeriod_2, /* From 1 to 200 */
                                int   *outBegIdx,
                                int   *outNbElement,
                                double       outMACD[],
                                double       outMACDSignal[],
                                double       outMACDHist[] )
#endif
{
   ARRAY_REF(slowEMABuffer);
   ARRAY_REF(fastEMABuffer);
   double k1, k2;
   TA_RetCode retCode;
   int tempInteger, outBegIdx1, outNbElement1;
   int outBegIdx2, outNbElement2;
   int lookbackTotal, lookbackSignal;
   int i;

   /* !!! A lot of speed optimization could be done
    * !!! with this function. 
    * !!!
    * !!! A better approach would be to use TA_INT_EMA
    * !!! just to get the seeding values for the
    * !!! fast and slow EMA. Then process the difference
    * !!! in an allocated buffer until enough data is
    * !!! available for the first signal value.
    * !!! From that point all the processing can
    * !!! be done in a tight loop.
    * !!!
    * !!! That approach will have the following
    * !!! advantage:
    * !!!   1) One mem allocation needed instead of two.
    * !!!   2) The mem allocation size will be only the
    * !!!      signal lookback period instead of the 
    * !!!      whole range of data.
    * !!!   3) Processing will be done in a tight loop.
    * !!!      allowing to avoid a lot of memory store-load
    * !!!      operation.
    * !!!   4) The memcpy at the end will be eliminated!
    * !!!
    * !!! If only I had time....
    */

   /* Make sure slow is really slower than
    * the fast period! if not, swap...
    */
   if( optInSlowPeriod < optInFastPeriod )
   {
       /* swap */
       tempInteger       = optInSlowPeriod;
       optInSlowPeriod = optInFastPeriod;
       optInFastPeriod = tempInteger;
   }

   /* Catch special case for fix 26/12 MACD. */
   if( optInSlowPeriod != 0 )
      k1 = PER_TO_K(optInSlowPeriod);
   else
   {
      optInSlowPeriod = 26;
      k1 = (double)0.075; /* Fix 26 */
   }

   if( optInFastPeriod != 0 )
      k2 = PER_TO_K(optInFastPeriod);
   else
   {
      optInFastPeriod = 12;
      k2 = (double)0.15; /* Fix 12 */
   }

   lookbackSignal = TA_EMA_Lookback( optInSignalPeriod_2 ); 

   /* Move up the start index if there is not
    * enough initial data.
    */
   lookbackTotal =  lookbackSignal;
   lookbackTotal += TA_EMA_Lookback( optInSlowPeriod );

   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }

   /* Allocate intermediate buffer for fast/slow EMA. */
   tempInteger = (endIdx-startIdx)+1+lookbackSignal;
   ARRAY_ALLOC( fastEMABuffer, tempInteger );
   if( !fastEMABuffer )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_ALLOC_ERR;
   }

   ARRAY_ALLOC( slowEMABuffer, tempInteger );
   if( !slowEMABuffer )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      ARRAY_FREE( fastEMABuffer );
      return TA_ALLOC_ERR;
   }

   /* Calculate the slow EMA. 
    *
    * Move back the startIdx to get enough data
    * for the signal period. That way, once the
    * signal calculation is done, all the output
    * will start at the requested 'startIdx'.
    */
   tempInteger = startIdx-lookbackSignal;
   retCode = TA_PREFIX(INT_EMA)( tempInteger, endIdx,
                                 inReal, optInSlowPeriod, k1,
                                 &outBegIdx1, &outNbElement1, slowEMABuffer );

   if( retCode != TA_SUCCESS )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      ARRAY_FREE( fastEMABuffer );
      ARRAY_FREE( slowEMABuffer );
      return retCode;
   }

   /* Calculate the fast EMA. */
   retCode = TA_PREFIX(INT_EMA)( tempInteger, endIdx,
                                 inReal, optInFastPeriod, k2,
                                 &outBegIdx2, &outNbElement2, fastEMABuffer );

   if( retCode != TA_SUCCESS )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      ARRAY_FREE( fastEMABuffer );
      ARRAY_FREE( slowEMABuffer );
      return retCode;
   }

   /* Parano tests. Will be removed eventually. */
   if( (outBegIdx1 != tempInteger) || 
       (outBegIdx2 != tempInteger) || 
       (outNbElement1 != outNbElement2) ||
       (outNbElement1 != (endIdx-startIdx)+1+lookbackSignal) )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      ARRAY_FREE( fastEMABuffer );
      ARRAY_FREE( slowEMABuffer );
      return TA_INTERNAL_ERROR(119);
   }

   /* Calculate (fast EMA) - (slow EMA). */
   for( i=0; i < outNbElement1; i++ )
      fastEMABuffer[i] = fastEMABuffer[i] - slowEMABuffer[i];


   /* Copy the result into the output for the caller. */
   ARRAY_MEMMOVE( outMACD, 0, fastEMABuffer, lookbackSignal, (endIdx-startIdx)+1 );

   /* Calculate the signal/trigger line. */
   retCode = TA_INT_EMA( 0, outNbElement1-1,
                         fastEMABuffer, optInSignalPeriod_2, PER_TO_K(optInSignalPeriod_2), 
                         &outBegIdx2, &outNbElement2, outMACDSignal );


   ARRAY_FREE( fastEMABuffer );
   ARRAY_FREE( slowEMABuffer );

   if( retCode != TA_SUCCESS )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return retCode;
   }

   /* Calculate the histogram. */
   for( i=0; i < outNbElement2; i++ )
      outMACDHist[i] = outMACD[i]-outMACDSignal[i];


   /* All done! Indicate the output limits and return success. */
   *outBegIdx     = startIdx;
   *outNbElement  = outNbElement2;

   return TA_SUCCESS;
}


/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::MACD( int    startIdx,
/* Generated */                                   int    endIdx,
/* Generated */                                   float        inReal __gc [],
/* Generated */                                   int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                   int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                   int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                                   [OutAttribute]Int32 *outBegIdx,
/* Generated */                                   [OutAttribute]Int32 *outNbElement,
/* Generated */                                   double        outMACD __gc [],
/* Generated */                                   double        outMACDSignal __gc [],
/* Generated */                                   double        outMACDHist __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_MACD( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       const float  inReal[],
/* Generated */                       int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                       int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                       int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                       int          *outBegIdx,
/* Generated */                       int          *outNbElement,
/* Generated */                       double        outMACD[],
/* Generated */                       double        outMACDSignal[],
/* Generated */                       double        outMACDHist[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if( !inReal ) return TA_BAD_PARAM;
/* Generated */     if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInFastPeriod = 12;
/* Generated */     else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInSlowPeriod = 26;
/* Generated */     else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( (int)optInSignalPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInSignalPeriod = 9;
/* Generated */     else if( ((int)optInSignalPeriod < 1) || ((int)optInSignalPeriod > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outMACD == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outMACDSignal == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outMACDHist == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    return TA_PREFIX(INT_MACD)( startIdx, endIdx, inReal,
/* Generated */                                optInFastPeriod,
/* Generated */                                optInSlowPeriod,
/* Generated */                                optInSignalPeriod,
/* Generated */                                outBegIdx,
/* Generated */                                outNbElement,
/* Generated */                                outMACD,
/* Generated */                                outMACDSignal,
/* Generated */                                outMACDHist );
/* Generated */ }
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::TA_INT_MACD( int    startIdx,
/* Generated */                                          int    endIdx,
/* Generated */                                          INPUT_TYPE inReal __gc [],
/* Generated */                                          int    optInFastPeriod, 
/* Generated */                                          int    optInSlowPeriod, 
/* Generated */                                          int    optInSignalPeriod_2, 
/* Generated */                                          [OutAttribute]Int32 *outBegIdx,
/* Generated */                                          [OutAttribute]Int32 *outNbElement,
/* Generated */                                          double outMACD __gc [],
/* Generated */                                          double outMACDSignal __gc [],
/* Generated */                                          double outMACDHist __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_PREFIX(INT_MACD)( int    startIdx,
/* Generated */                                 int    endIdx,
/* Generated */                                 const INPUT_TYPE inReal[],
/* Generated */                                 int    optInFastPeriod, 
/* Generated */                                 int    optInSlowPeriod, 
/* Generated */                                 int    optInSignalPeriod_2, 
/* Generated */                                 int   *outBegIdx,
/* Generated */                                 int   *outNbElement,
/* Generated */                                 double       outMACD[],
/* Generated */                                 double       outMACDSignal[],
/* Generated */                                 double       outMACDHist[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    ARRAY_REF(slowEMABuffer);
/* Generated */    ARRAY_REF(fastEMABuffer);
/* Generated */    double k1, k2;
/* Generated */    TA_RetCode retCode;
/* Generated */    int tempInteger, outBegIdx1, outNbElement1;
/* Generated */    int outBegIdx2, outNbElement2;
/* Generated */    int lookbackTotal, lookbackSignal;
/* Generated */    int i;
/* Generated */    if( optInSlowPeriod < optInFastPeriod )
/* Generated */    {
/* Generated */        tempInteger       = optInSlowPeriod;
/* Generated */        optInSlowPeriod = optInFastPeriod;
/* Generated */        optInFastPeriod = tempInteger;
/* Generated */    }
/* Generated */    if( optInSlowPeriod != 0 )
/* Generated */       k1 = PER_TO_K(optInSlowPeriod);
/* Generated */    else
/* Generated */    {
/* Generated */       optInSlowPeriod = 26;
/* Generated */       k1 = (double)0.075; 
/* Generated */    }
/* Generated */    if( optInFastPeriod != 0 )
/* Generated */       k2 = PER_TO_K(optInFastPeriod);
/* Generated */    else
/* Generated */    {
/* Generated */       optInFastPeriod = 12;
/* Generated */       k2 = (double)0.15; 
/* Generated */    }
/* Generated */    lookbackSignal = TA_EMA_Lookback( optInSignalPeriod_2 ); 
/* Generated */    lookbackTotal =  lookbackSignal;
/* Generated */    lookbackTotal += TA_EMA_Lookback( optInSlowPeriod );
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return TA_SUCCESS;
/* Generated */    }
/* Generated */    tempInteger = (endIdx-startIdx)+1+lookbackSignal;
/* Generated */    ARRAY_ALLOC( fastEMABuffer, tempInteger );
/* Generated */    if( !fastEMABuffer )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return TA_ALLOC_ERR;
/* Generated */    }
/* Generated */    ARRAY_ALLOC( slowEMABuffer, tempInteger );
/* Generated */    if( !slowEMABuffer )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       ARRAY_FREE( fastEMABuffer );
/* Generated */       return TA_ALLOC_ERR;
/* Generated */    }
/* Generated */    tempInteger = startIdx-lookbackSignal;
/* Generated */    retCode = TA_PREFIX(INT_EMA)( tempInteger, endIdx,
/* Generated */                                  inReal, optInSlowPeriod, k1,
/* Generated */                                  &outBegIdx1, &outNbElement1, slowEMABuffer );
/* Generated */    if( retCode != TA_SUCCESS )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       ARRAY_FREE( fastEMABuffer );
/* Generated */       ARRAY_FREE( slowEMABuffer );
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    retCode = TA_PREFIX(INT_EMA)( tempInteger, endIdx,
/* Generated */                                  inReal, optInFastPeriod, k2,
/* Generated */                                  &outBegIdx2, &outNbElement2, fastEMABuffer );
/* Generated */    if( retCode != TA_SUCCESS )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       ARRAY_FREE( fastEMABuffer );
/* Generated */       ARRAY_FREE( slowEMABuffer );
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    if( (outBegIdx1 != tempInteger) || 
/* Generated */        (outBegIdx2 != tempInteger) || 
/* Generated */        (outNbElement1 != outNbElement2) ||
/* Generated */        (outNbElement1 != (endIdx-startIdx)+1+lookbackSignal) )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       ARRAY_FREE( fastEMABuffer );
/* Generated */       ARRAY_FREE( slowEMABuffer );
/* Generated */       return TA_INTERNAL_ERROR(119);
/* Generated */    }
/* Generated */    for( i=0; i < outNbElement1; i++ )
/* Generated */       fastEMABuffer[i] = fastEMABuffer[i] - slowEMABuffer[i];
/* Generated */    ARRAY_MEMMOVE( outMACD, 0, fastEMABuffer, lookbackSignal, (endIdx-startIdx)+1 );
/* Generated */    retCode = TA_INT_EMA( 0, outNbElement1-1,
/* Generated */                          fastEMABuffer, optInSignalPeriod_2, PER_TO_K(optInSignalPeriod_2), 
/* Generated */                          &outBegIdx2, &outNbElement2, outMACDSignal );
/* Generated */    ARRAY_FREE( fastEMABuffer );
/* Generated */    ARRAY_FREE( slowEMABuffer );
/* Generated */    if( retCode != TA_SUCCESS )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    for( i=0; i < outNbElement2; i++ )
/* Generated */       outMACDHist[i] = outMACD[i]-outMACDSignal[i];
/* Generated */    *outBegIdx     = startIdx;
/* Generated */    *outNbElement  = outNbElement2;
/* Generated */    return TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

