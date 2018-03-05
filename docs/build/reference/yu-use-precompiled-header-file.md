---
title: "-Yu (usar arquivo de cabeçalho pré-compilado) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /yu
dev_langs:
- C++
helpviewer_keywords:
- Yu compiler option [C++]
- /Yu compiler option [C++]
- -Yu compiler option [C++]
- PCH files, use existing
- .pch files, use existing
- precompiled header files, use existing
ms.assetid: 24f1bd0e-b624-4296-a17e-d4b53e374e1f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c83f159882b9ed6fcfe5557c150413303c401dda
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="yu-use-precompiled-header-file"></a>/Yu (usar arquivo de cabeçalho pré-compilado)
Instrui o compilador para usar um arquivo de cabeçalho pré-compilado (. pch) existente na compilação atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Yu[filename]  
```  
  
## <a name="arguments"></a>Arguments  
 *filename*  
 O nome de um arquivo de cabeçalho, que está incluído no arquivo de origem usando um **#include** diretiva de pré-processamento.  
  
## <a name="remarks"></a>Comentários  
 O nome do arquivo de inclusão deve ser o mesmo para ambos os **/Yc** opção que cria o cabeçalho pré-compilado e qualquer subsequentes **/Yu** opção indicando o uso do cabeçalho pré-compilado.  
  
 Para **/Yc**, `filename` Especifica o ponto no qual pré-compilação parar; o compilador pré-compila todo o código que `filename` e nomes de cabeçalho pré-compilado resultante usando o nome base do arquivo de inclusão e uma extensão de. pch.  
  
 O arquivo. pch deve ter sido criado usando **/Yc**.  
  
 O compilador trata todo o código que ocorrem antes do arquivo. h como pré-compilado. Ele ignora apenas posterior a **#include** diretiva associada ao arquivo. h, usa o código contido no arquivo. pch e, em seguida, compila todo o código após `filename`.  
  
 Na linha de comando, não são permitidos espaços entre **/Yu** e `filename`.  
  
 Quando você especifica o **/Yu** opção sem um nome de arquivo, o programa de origem deve conter um [#pragma hdrstop](../../preprocessor/hdrstop.md) pragma que especifica o nome do arquivo de cabeçalho pré-compilado, o arquivo. pch. Nesse caso, o compilador usará o cabeçalho pré-compilado (arquivo. pch) nomeado pelo [/Fp (nome. O arquivo pch)](../../build/reference/fp-name-dot-pch-file.md). O compilador vai para o local desse pragma, restaura o estado compilado do arquivo de cabeçalho pré-compilado especificado pelo pragma e, em seguida, compila somente o código que segue o pragma. Se **#pragma hdrstop** não especificar um nome de arquivo, o compilador procura um arquivo com um nome derivado do nome de base do arquivo de origem com uma extensão. pch. Você também pode usar o **/Fp** opção para especificar um arquivo. pch diferentes.  
  
 Se você especificar o **/Yu** opção sem um nome de arquivo e não especificar um **hdrstop** pragma, uma mensagem de erro é gerada e a compilação for bem-sucedida.  
  
 Se o **/Yc** `filename` e **/Yu** `filename` opções ocorrem na mesma linha de comando e o mesmo nome de arquivo, tanto de referência **/Yc** `filename` usa precedência, todo o código de pré-compilação até e incluindo o arquivo nomeado. Esse recurso simplifica a gravação de makefiles.  
  
 Como arquivos. pch contêm informações sobre o ambiente de máquina, bem como informações de endereço de memória sobre o programa, você deve usar apenas um arquivo pch no computador em que ele foi criado.  
  
 Para obter mais informações sobre cabeçalhos pré-compilados, consulte:  
  
-   [/Y (cabeçalhos pré-compilados)](../../build/reference/y-precompiled-headers.md)  
  
-   [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Especifique [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) em um arquivo. cpp no seu projeto.  
  
2.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
3.  Clique o **C/C++** pasta.  
  
4.  Clique o **cabeçalhos pré-compilados** página de propriedades.  
  
5.  Modificar o **criar/usar PCH através de arquivo** propriedade ou o **criar/usar cabeçalho de pré-compilado** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PrecompiledHeaderThrough%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A>.  
  
## <a name="examples"></a>Exemplos  
 Se o código a seguir:  
  
```  
#include <afxwin.h>   // Include header for class library  
#include "resource.h" // Include resource definitions  
#include "myapp.h"    // Include information specific to this app  
...  
```  
  
 é compilado com a linha de comando `CL /YuMYAPP.H PROG.CPP`, o compilador não processa os três incluem instruções, mas usa pré-compilado código de MYAPP.pch, assim, salvando o tempo envolvido no pré-processamento todos os três arquivos (e todos os arquivos podem incluir).  
  
 Você pode usar o [/Fp (nome. O arquivo pch)](../../build/reference/fp-name-dot-pch-file.md) opção com o **/Yu** opção para especificar o nome do arquivo. pch se o nome é diferente do que o argumento de nome de arquivo para **/Yc** ou o nome base do arquivo de origem, como no a seguir:  
  
```  
CL /YuMYAPP.H /FpMYPCH.pch PROG.CPP  
```  
  
 Este comando Especifica um arquivo de cabeçalho pré-compilado chamado MYPCH.pch. O compilador usa seu conteúdo para restaurar o estado de todos os arquivos de cabeçalho até e incluindo MYAPP.h do pré-compilado. O compilador, em seguida, compila o código que ocorre após o MYAPP.h **incluem** instrução.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)