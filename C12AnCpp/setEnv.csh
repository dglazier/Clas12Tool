setenv CLAS12TOOL $HOME/software/Clas12Tool

#check if ROOT exist
if ( ! $?ROOTSYS )  then
  echo "ATTENTION: ROOTSYS is not set. Do you have ROOT installed?"
endif

setenv HIPO ${CLAS12TOOL}"/Hipo"

setenv CLAS12CPPBASE ${CLAS12TOOL}"/C12AnCpp"
echo $CLAS12CPPBASE

setenv C12CORE ${CLAS12CPPBASE}"/Core"
setenv C12CLAS12 ${CLAS12CPPBASE}"/Clas12"
setenv C12RTOOL ${CLAS12CPPBASE}"/Root"
setenv C12TOOLS ${CLAS12CPPBASE}"/Tools"
setenv C12LUND ${CLAS12CPPBASE}"/Lund"
setenv CLAS12CPP ${C12CORE}:${C12CLAS12}:${C12RTOOL}:${C12TOOLS}:${C12LUND}

setenv LD_LIBRARY_PATH ${CLAS12CPP}:${CLAS12TOOL}"/lib":${HIPO}:${LD_LIBRARY_PATH}
echo $LD_LIBRARY_PATH

