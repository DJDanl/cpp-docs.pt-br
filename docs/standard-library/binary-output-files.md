---
title: Arquivos de Saída Binários
ms.date: 11/04/2016
helpviewer_keywords:
- I/O [C++], binary output files
- files [C++], binary output files
- binary data, binary output files
ms.assetid: 180954af-8cd6-444b-9a76-2f630a3389d8
ms.openlocfilehash: 4562f5c1167aeadc6689313e73545ed1ad9bbcf8
ms.sourcegitcommit: 878a164fe6d550ca81ab87d8425c8d3cd52fe384
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/22/2019
ms.locfileid: "68376339"
---
# <a name="binary-output-files"></a>Arquivos de Saída Binários

Os fluxos foram criados originalmente para texto, portanto, o modo de saída padrão é texto. No modo de texto, o caractere de alimentação de linha (nova) expande para um par de retorno de carro-alimentação de linha. A expansão pode causar problemas, como é mostrado aqui:

```cpp
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

Você pode esperar que este programa produza a sequência de bytes { 99, 0, 10, 0 }, mas ele produz { 99, 0, 13, 10, 0 }, o que causa problemas para um programa que espera uma entrada binária. Se você precisar de uma saída binária verdadeira, na qual os caracteres são gravados não traduzidos, você poderá especificar a saída binária `openmode` usando o argumento do Construtor [ofstream](../standard-library/basic-ofstream-class.md#basic_ofstream):

```cpp
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
