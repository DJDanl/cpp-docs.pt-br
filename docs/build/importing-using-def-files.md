---
title: Importando usando arquivos DEF
ms.date: 11/04/2016
helpviewer_keywords:
- importing DLLs [C++], DEF files
- def files [C++], importing with
- .def files [C++], importing with
- dllimport attribute [C++], DEF files
- DLLs [C++], DEF files
ms.assetid: aefdbf50-f603-488a-b0d7-ed737bae311d
ms.openlocfilehash: e4ac48dc013874c240411f78a733d32e116df25d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223961"
---
# <a name="importing-using-def-files"></a>Importando usando arquivos DEF

Se você optar por usar **`__declspec(dllimport)`** o juntamente com um arquivo. def, deverá alterar o arquivo. def para usar dados no lugar de constante para reduzir a probabilidade de que a codificação incorreta cause um problema:

```
// project.def
LIBRARY project
EXPORTS
   ulDataInDll   DATA
```

A tabela a seguir mostra o porquê.

|Palavra-chave|Emitidos na biblioteca de importação|Port|
|-------------|---------------------------------|-------------|
|`CONSTANT`|`_imp_ulDataInDll`, `_ulDataInDll`|`_ulDataInDll`|
|`DATA`|`_imp_ulDataInDll`|`_ulDataInDll`|

O uso de **`__declspec(dllimport)`** and Constant lista a `imp` versão e o nome não decorado na biblioteca de importação dll. lib que é criada para permitir vinculação explícita. Usando o **`__declspec(dllimport)`** e o lista de dados apenas a `imp` versão do nome.

Se você usar constante, qualquer uma das seguintes construções de código poderá ser usada para acessar `ulDataInDll` :

```
__declspec(dllimport) ULONG ulDataInDll; /*prototype*/
if (ulDataInDll == 0L)   /*sample code fragment*/
```

\-ou-

```
ULONG *ulDataInDll;      /*prototype*/
if (*ulDataInDll == 0L)  /*sample code fragment*/
```

No entanto, se você usar dados em seu arquivo. def, somente o código compilado com a seguinte definição poderá acessar a variável `ulDataInDll` :

```
__declspec(dllimport) ULONG ulDataInDll;

if (ulDataInDll == 0L)   /*sample code fragment*/
```

Usar a constante é mais arriscado porque se você esquecer de usar o nível extra de indireção, poderá potencialmente acessar o ponteiro da tabela de endereços de importação para a variável, não a variável em si. Esse tipo de problema geralmente pode ser manifestado como uma violação de acesso porque a tabela de endereços de importação é atualmente feita como somente leitura pelo compilador e pelo vinculador.

O vinculador MSVC atual emite um aviso se ele vê constante no arquivo. def para considerar esse caso. O único motivo para usar a constante é que se você não puder recompilar algum arquivo de objeto em que o arquivo de cabeçalho não tenha sido listado **`__declspec(dllimport)`** no protótipo.

## <a name="see-also"></a>Confira também

[Importando para um aplicativo](importing-into-an-application.md)
