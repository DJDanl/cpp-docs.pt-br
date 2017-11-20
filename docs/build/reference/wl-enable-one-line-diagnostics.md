---
title: "-WL (habilitar diagnóstico de uma linha) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /wl
dev_langs: C++
helpviewer_keywords:
- -WL compiler option [C++]
- /WL compiler option [C++]
- WL compiler option [C++]
ms.assetid: 332cadb4-8ea6-45fe-b67d-33ddec1f2c2e
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 74591dab7c47a8ffc36c357a6c53acb25563e382
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="wl-enable-one-line-diagnostics"></a>/WL (habilitar diagnóstico de uma linha)
Acrescenta informações adicionais para uma mensagem de erro ou aviso.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/WL  
```  
  
## <a name="remarks"></a>Comentários  
 Mensagens de erro e aviso do compilador do C++ podem ser seguidas de informações adicionais que aparece, por padrão, em uma nova linha. Quando você compila na linha de comando, a linha adicional de informações pode ser anexada à mensagem de erro ou aviso. Isso pode ser desejável se você capturar a saída de compilação para um arquivo de log e, em seguida, processar esse log para localizar todos os erros e avisos. Um ponto e vírgula separará a mensagem de aviso ou erro na linha de adicionais.  
  
 Nem todas as mensagens de erro e aviso tem uma linha adicional de informações. O código a seguir gerará um erro que tenha uma linha adicional de informações. ela permitirá que você teste o efeito quando você usar **/WL**.  
  
```  
// compiler_option_WL.cpp  
// compile with: /WL  
#include <queue>  
int main() {  
   std::queue<int> q;  
   q.fromthecontinuum();   // C2039  
}  
```  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)