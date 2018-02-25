---
title: "Arquivos de saída binários | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- I/O [C++], binary output files
- files [C++], binary output files
- binary data, binary output files
ms.assetid: 180954af-8cd6-444b-9a76-2f630a3389d8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 932b2bdd756309fa4fb84f9cf2b06d171d299a43
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="binary-output-files"></a>Arquivos de Saída Binários
Os fluxos foram criados originalmente para texto, portanto, o modo de saída padrão é texto. No modo de texto, o caractere de nova linha (10 hexadecimal) se expande para um carro retorno-alimentação de linha (somente 16 bits). A expansão pode causar problemas, como é mostrado aqui:  
  
```  
// binary_output_files.cpp  
// compile with: /EHsc  
#include <fstream>  
using namespace std;  
int iarray[2] = { 99, 10 };  
int main( )  
{  
    ofstream os( "test.dat" );  
    os.write( (char *) iarray, sizeof( iarray ) );  
}  
```  
  
 Você pode esperar que este programa produza a sequência de bytes { 99, 0, 10, 0 }, mas ele produz { 99, 0, 13, 10, 0 }, o que causa problemas para um programa que espera uma entrada binária. Se você precisar de uma saída binária verdadeira, na qual os caracteres são escritos sem conversão, especifique a saída binária usando o argumento openmode do construtor [ofstream](../standard-library/basic-ofstream-class.md#basic_ofstream):  
  
```  
// binary_output_files2.cpp  
// compile with: /EHsc  
#include <fstream>  
using namespace std;  
int iarray[2] = { 99, 10 };  
  
int main()  
{  
   ofstream ofs ( "test.dat", ios_base::binary );  
  
   // Exactly 8 bytes written  
   ofs.write( (char*)&iarray[0], sizeof(int)*2 );   
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de saída](../standard-library/output-streams.md)

