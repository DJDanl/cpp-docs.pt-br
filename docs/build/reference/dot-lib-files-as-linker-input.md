---
title: . Lib arquivos como entrada de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.AdditionalDependencies
dev_langs:
- C++
helpviewer_keywords:
- OMF libraries
- linking [C++], OMF libraries
- import libraries, linker files
- libraries [C++], .lib files as linker input
- COFF files, import libraries
- default libraries [C++], linker output
- default libraries [C++]
- defaults [C++], libraries
- .lib files
ms.assetid: dc5d2b1c-2487-41fa-aa71-ad1e0647958b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8382e43398c4b6e5241542e6b41fdee8e2f70eff
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32374538"
---
# <a name="lib-files-as-linker-input"></a>Arquivos .Lib como entrada de vinculador
LINK aceita bibliotecas padrão COFF e COFF importar bibliotecas, que geralmente têm a extensão. lib. Bibliotecas padrão contêm objetos e são criadas pela ferramenta LIB. Bibliotecas de importação contêm informações sobre exportações em outros programas e são criadas pelo LINK quando ele cria um programa que contém exportações ou pela ferramenta LIB. Para obter informações sobre como usar LIB para criar um padrão ou bibliotecas de importação, consulte [referência LIB](../../build/reference/lib-reference.md). Para obter detalhes sobre como usar o LINK para criar uma biblioteca de importação, consulte o [/DLL](../../build/reference/dll-build-a-dll.md) opção.  
  
Uma biblioteca é especificada para o LINK como um argumento de nome de arquivo ou uma biblioteca padrão. LINK resolve referências externas pesquisando primeiro bibliotecas especificadas na linha de comando, em seguida, padrão bibliotecas especificado com o [/DEFAULTLIB](../../build/reference/defaultlib-specify-default-library.md) opção, e, em seguida, padrão bibliotecas nomeados em arquivos. obj. Se um caminho for especificado com o nome da biblioteca, o LINK procura a biblioteca no diretório. Se nenhum caminho for especificado, o LINK procura primeiro no diretório que está executando o LINK do e, em seguida, em qualquer diretório especificado na variável de ambiente LIB.  
  
## <a name="to-add-lib-files-as-linker-input-in-the-development-environment"></a>Para adicionar arquivos. lib como entrada de vinculador no ambiente de desenvolvimento  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Escolha o **entrada** página de propriedades no **vinculador** pasta.  
  
3.  Modificar o **dependências adicionais** propriedade para adicionar os arquivos. lib.  
  
## <a name="to-programmatically-add-lib-files-as-linker-input"></a>Para adicionar programaticamente os arquivos. lib como entrada de vinculador  
  
-   Consulte [AdditionalDependencies](https://msdn.microsoft.com/library/microsoft.visualstudio.vcprojectengine.vclinkertool.additionaldependencies.aspx).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir mostra como criar e usar um arquivo. Primeiro, crie um arquivo. lib:  
  
```cpp  
// lib_link_input_1.cpp  
// compile by using: cl /LD lib_link_input_1.cpp  
__declspec(dllexport) int Test() {  
   return 213;  
}  
```  
  
E, em seguida, compile Este exemplo usando o arquivo. lib que você acabou de criar:  
  
```cpp  
// lib_link_input_2.cpp  
// compile by using: cl /EHsc lib_link_input_1.lib lib_link_input_2.cpp   
__declspec(dllimport) int Test();  
#include <iostream>  
int main() {  
   std::cout << Test() << std::endl;  
}  
```  
  
```Output  
213  
```  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de entrada de LINK](../../build/reference/link-input-files.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)