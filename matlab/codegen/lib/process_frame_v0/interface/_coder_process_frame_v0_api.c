/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_process_frame_v0_api.c
 *
 * Code generation for function '_coder_process_frame_v0_api'
 *
 */

/* Include files */
#include "tmwtypes.h"
#include "_coder_process_frame_v0_api.h"
#include "_coder_process_frame_v0_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
static const mxArray *eml_mx;
static const mxArray *b_eml_mx;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "process_frame_v0",                  /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

static emlrtMCInfo emlrtMCI = { -1,    /* lineNo */
  -1,                                  /* colNo */
  "",                                  /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, int32_T y[1024]);
static boolean_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *reset,
  const char_T *identifier);
static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const mxArray *src, int32_T ret[1024]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *frame_in,
  const char_T *identifier, int32_T y[1024]);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const int32_T u
  [1024]);
static boolean_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static const mxArray *fimath(const emlrtStack *sp, const char * b, const char
  * c, const char * d, const char * e, const char * f, const char * g, const
  char * h, const char * i, const char * j, const char * k, const char * l,
  const char * m, const char * n, real_T o, const char * p, real_T q, const char
  * r, real_T s, const char * t, real_T u, const char * v, real_T w, const char *
  x, real_T y, const char * ab, real_T bb, const char * cb, real_T db, const
  char * eb, real_T fb, const char * gb, real_T hb, const char * ib, real_T jb,
  const char * kb, real_T lb, const char * mb, boolean_T nb, const char * ob,
  real_T pb, const char * qb, real_T rb, emlrtMCInfo *location);
static const mxArray *numerictype(const emlrtStack *sp, const char * b, real_T c,
  const char * d, real_T e, const char * f, real_T g, const char * h, real_T i,
  const char * j, real_T k, emlrtMCInfo *location);
static void process_frame_v0_once(const emlrtStack *sp);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, int32_T y[1024])
{
  static const int32_T dims[2] = { 1, 1024 };

  emlrtCheckFiR2012b(sp, parentId, u, false, 2U, dims, (const mxArray *)eml_mx,
                     (const mxArray *)b_eml_mx);
  e_emlrt_marshallIn(emlrtAlias(u), y);
  emlrtDestroyArray(&u);
}

static boolean_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *reset,
  const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(reset), &thisId);
  emlrtDestroyArray(&reset);
  return y;
}

static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const mxArray *src, int32_T ret[1024])
{
  const mxArray *mxInt;
  int32_T i0;
  mxInt = emlrtImportFiIntArrayR2008b(src);
  for (i0 = 0; i0 < 1024; i0++) {
    ret[i0] = (*(int32_T (*)[1024])emlrtMxGetData(mxInt))[i0];
  }

  emlrtDestroyArray(&mxInt);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *frame_in,
  const char_T *identifier, int32_T y[1024])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(frame_in), &thisId, y);
  emlrtDestroyArray(&frame_in);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const int32_T u
  [1024])
{
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 1024 };

  int32_T (*pData)[1024];
  int32_T i;
  y = NULL;
  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxINT32_CLASS, mxREAL);
  pData = (int32_T (*)[1024])emlrtMxGetData(m0);
  for (i = 0; i < 1024; i++) {
    (*pData)[i] = u[i];
  }

  emlrtAssign(&b_y, m0);
  emlrtAssign(&y, emlrtCreateFIR2013b(sp, (const mxArray *)eml_mx, (const
    mxArray *)b_eml_mx, "simulinkarray", b_y, true, false));
  return y;
}

static boolean_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static const mxArray *fimath(const emlrtStack *sp, const char * b, const char
  * c, const char * d, const char * e, const char * f, const char * g, const
  char * h, const char * i, const char * j, const char * k, const char * l,
  const char * m, const char * n, real_T o, const char * p, real_T q, const char
  * r, real_T s, const char * t, real_T u, const char * v, real_T w, const char *
  x, real_T y, const char * ab, real_T bb, const char * cb, real_T db, const
  char * eb, real_T fb, const char * gb, real_T hb, const char * ib, real_T jb,
  const char * kb, real_T lb, const char * mb, boolean_T nb, const char * ob,
  real_T pb, const char * qb, real_T rb, emlrtMCInfo *location)
{
  const mxArray *pArrays[42];
  const mxArray *m2;
  pArrays[0] = emlrtCreateString(b);
  pArrays[1] = emlrtCreateString(c);
  pArrays[2] = emlrtCreateString(d);
  pArrays[3] = emlrtCreateString(e);
  pArrays[4] = emlrtCreateString(f);
  pArrays[5] = emlrtCreateString(g);
  pArrays[6] = emlrtCreateString(h);
  pArrays[7] = emlrtCreateString(i);
  pArrays[8] = emlrtCreateString(j);
  pArrays[9] = emlrtCreateString(k);
  pArrays[10] = emlrtCreateString(l);
  pArrays[11] = emlrtCreateString(m);
  pArrays[12] = emlrtCreateString(n);
  pArrays[13] = emlrtCreateDoubleScalar(o);
  pArrays[14] = emlrtCreateString(p);
  pArrays[15] = emlrtCreateDoubleScalar(q);
  pArrays[16] = emlrtCreateString(r);
  pArrays[17] = emlrtCreateDoubleScalar(s);
  pArrays[18] = emlrtCreateString(t);
  pArrays[19] = emlrtCreateDoubleScalar(u);
  pArrays[20] = emlrtCreateString(v);
  pArrays[21] = emlrtCreateDoubleScalar(w);
  pArrays[22] = emlrtCreateString(x);
  pArrays[23] = emlrtCreateDoubleScalar(y);
  pArrays[24] = emlrtCreateString(ab);
  pArrays[25] = emlrtCreateDoubleScalar(bb);
  pArrays[26] = emlrtCreateString(cb);
  pArrays[27] = emlrtCreateDoubleScalar(db);
  pArrays[28] = emlrtCreateString(eb);
  pArrays[29] = emlrtCreateDoubleScalar(fb);
  pArrays[30] = emlrtCreateString(gb);
  pArrays[31] = emlrtCreateDoubleScalar(hb);
  pArrays[32] = emlrtCreateString(ib);
  pArrays[33] = emlrtCreateDoubleScalar(jb);
  pArrays[34] = emlrtCreateString(kb);
  pArrays[35] = emlrtCreateDoubleScalar(lb);
  pArrays[36] = emlrtCreateString(mb);
  pArrays[37] = emlrtCreateLogicalScalar(nb);
  pArrays[38] = emlrtCreateString(ob);
  pArrays[39] = emlrtCreateDoubleScalar(pb);
  pArrays[40] = emlrtCreateString(qb);
  pArrays[41] = emlrtCreateDoubleScalar(rb);
  return emlrtCallMATLABR2012b(sp, 1, &m2, 42, pArrays, "fimath", true, location);
}

static const mxArray *numerictype(const emlrtStack *sp, const char * b, real_T c,
  const char * d, real_T e, const char * f, real_T g, const char * h, real_T i,
  const char * j, real_T k, emlrtMCInfo *location)
{
  const mxArray *pArrays[10];
  const mxArray *m1;
  pArrays[0] = emlrtCreateString(b);
  pArrays[1] = emlrtCreateDoubleScalar(c);
  pArrays[2] = emlrtCreateString(d);
  pArrays[3] = emlrtCreateDoubleScalar(e);
  pArrays[4] = emlrtCreateString(f);
  pArrays[5] = emlrtCreateDoubleScalar(g);
  pArrays[6] = emlrtCreateString(h);
  pArrays[7] = emlrtCreateDoubleScalar(i);
  pArrays[8] = emlrtCreateString(j);
  pArrays[9] = emlrtCreateDoubleScalar(k);
  return emlrtCallMATLABR2012b(sp, 1, &m1, 10, pArrays, "numerictype", true,
    location);
}

static void process_frame_v0_once(const emlrtStack *sp)
{
  emlrtAssignP((const mxArray **)&b_eml_mx, NULL);
  emlrtAssignP((const mxArray **)&eml_mx, NULL);
  emlrtAssignP((const mxArray **)&b_eml_mx, numerictype(sp, "WordLength", 32.0,
    "FractionLength", 28.0, "BinaryPoint", 28.0, "Slope", 3.7252902984619141E-9,
    "FixedExponent", -28.0, (emlrtMCInfo *)&emlrtMCI));
  emlrtAssignP((const mxArray **)&eml_mx, fimath(sp, "RoundMode", "nearest",
    "RoundingMethod", "Nearest", "OverflowMode", "wrap", "OverflowAction",
    "Wrap", "ProductMode", "FullPrecision", "SumMode", "FullPrecision",
    "ProductWordLength", 32.0, "SumWordLength", 32.0, "MaxProductWordLength",
    65535.0, "MaxSumWordLength", 65535.0, "ProductFractionLength", 30.0,
    "ProductFixedExponent", -30.0, "SumFractionLength", 30.0, "SumFixedExponent",
    -30.0, "SumSlopeAdjustmentFactor", 1.0, "SumBias", 0.0,
    "ProductSlopeAdjustmentFactor", 1.0, "ProductBias", 0.0, "CastBeforeSum",
    true, "SumSlope", 9.3132257461547852E-10, "ProductSlope",
    9.3132257461547852E-10, (emlrtMCInfo *)&emlrtMCI));
}

void process_frame_v0_api(const mxArray * const prhs[5], const mxArray *plhs[1])
{
  static const uint32_T Structure[4] = { 2566760680U, 4073167059U, 2753257710U,
    2628856578U };

  static const uint32_T SOSMatrix[4] = { 2033089180U, 1508195269U, 1758489295U,
    953770011U };

  static const uint32_T ScaleValues[4] = { 3166131777U, 1019464021U, 4078028061U,
    1220847577U };

  int32_T frame_in[1024];
  boolean_T reset;
  int32_T frame_out[1024];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check constant function inputs */
  emlrtCheckArrayChecksumR2014a(&st, "Structure", Structure, prhs[2], false);
  emlrtCheckArrayChecksumR2014a(&st, "SOSMatrix", SOSMatrix, prhs[3], false);
  emlrtCheckArrayChecksumR2014a(&st, "ScaleValues", ScaleValues, prhs[4], false);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[0]), "frame_in",
                   frame_in);
  reset = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]), "reset");

  /* Invoke the target function */
  process_frame_v0(frame_in, reset, frame_out);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, frame_out);
}

void process_frame_v0_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  process_frame_v0_xil_terminate();
  emlrtDestroyArray((const mxArray **)&eml_mx);
  emlrtDestroyArray((const mxArray **)&b_eml_mx);
}

void process_frame_v0_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 3U, "ForceOff");
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    process_frame_v0_once(&st);
  }
}

void process_frame_v0_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_process_frame_v0_api.c) */
