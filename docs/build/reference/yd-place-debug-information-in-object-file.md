---
title: -Yd (colocar informações de depuração no arquivo de objeto) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /yd
dev_langs:
- C++
helpviewer_keywords:
- /Yd compiler option [C++]
- -Yd compiler option [C++]
- debugging [C++], debug information files
- Yd compiler option [C++]
ms.assetid: c5a699fe-65ce-461e-964c-7f5eb2a8320a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 39b03b0faf975caba8c5a287c88afcdf53f7a71f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="yd-place-debug-information-in-object-file"></a>/Yd (colocar informações de depuração no arquivo de projeto)
Prova completa de depuração informações em todos os arquivos de objeto criado a partir de um arquivo de cabeçalho pré-compilado (. pch) quando usado com o [/Yc](../../build/reference/yc-create-precompiled-header-file.md) e [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md) opções. Preterido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Yd  
```  
  
## <a name="remarks"></a>Comentários  
 **/Yd** é preterido; [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] agora oferece suporte ao uso de vários objetos de gravar em um arquivo. PDB único, **/Zi** em vez disso. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções do compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
 A menos que você precisa distribuir informações de depuração que contém uma biblioteca, use o [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção em vez de **/Z7** e **/Yd**.  
  
 Armazenando informações de depuração completas em todos os arquivos. obj só é necessário para distribuir as bibliotecas que contenham informações de depuração. Ela reduz a compilação e requer espaço em disco considerável. Quando **/Yc** e **/Z7** são usados sem **/Yd**, o compilador armazena informações de depuração comuns no primeiro arquivo. obj criado a partir do arquivo. pch. O compilador não inserir essas informações em arquivos. obj subsequentemente criados do arquivo. pch; ele insere referências cruzadas para as informações. Independentemente de quantos arquivos. obj usam o arquivo. pch, apenas um arquivo. obj contém as informações de depuração comuns.  
  
 Embora essa resultados de comportamento padrão mais rápido criar vezes e reduz as exigências de espaço em disco, não é desejável, se uma pequena alteração requer a recriação do arquivo. obj que contém as informações de depuração comuns. Nesse caso, o compilador deve recriar todos os arquivos. obj, que contém referências cruzadas no arquivo. obj original. Além disso, se um arquivo. pch comum é usado por projetos diferentes, a dependência de referências cruzadas para um arquivo. obj único é difícil.  
  
 Para obter mais informações sobre cabeçalhos pré-compilados, consulte:  
  
-   [/Y (cabeçalhos pré-compilados)](../../build/reference/y-precompiled-headers.md)  
  
-   [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="examples"></a>Exemplos  
 Suponha que você tem dois arquivos de base, F.cpp e G.cpp, cada uma contendo esses **#include** instruções:  
  
```  
#include "windows.h"  
#include "etc.h"  
```  
  
 O comando a seguir cria o cabeçalho pré-compilado ETC.pch e o arquivo de objeto F.obj arquivo:  
  
```  
CL /YcETC.H /Z7 F.CPP  
```  
  
 O arquivo de objeto F.obj inclui o tipo e informações de símbolo para Windows. h e ETC.h (e outros arquivos de cabeçalho incluem). Agora você pode usar o cabeçalho pré-compilado ETC.pch para compilar o arquivo de origem G.cpp:  
  
```  
CL /YuETC.H /Z7 G.CPP  
```  
  
 O arquivo de objeto G.obj não inclui as informações de depuração para o cabeçalho pré-compilado, mas simplesmente faz referência a essas informações no arquivo F.obj. Observe que você deve estabelecer um vínculo com o arquivo F.obj.  
  
 Se o cabeçalho pré-compilado não foi compilado com **/Z7**, você ainda pode usá-lo em compilações posteriores usando **/Z7**. No entanto, as informações de depuração são colocadas no arquivo do objeto atual e símbolos locais para funções e tipos definidos no cabeçalho pré-compilado não estão disponíveis para o depurador.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)