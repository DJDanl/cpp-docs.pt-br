---
title: Ferramentas de vinculador LNK2038 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2038
dev_langs:
- C++
helpviewer_keywords:
- LNK2038
ms.assetid: b8d0fb35-eee6-4f52-b3c4-239cb4f65656
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: af1249f84f03b19a7466410009661415c359e88e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2038"></a>Erro das Ferramentas de Vinculador LNK2038
detectada incompatibilidade de '\<nome >': valor '\<valor 1 >' não corresponde o valor '\<valor 2 >' em \<filename.obj >  
  
 Foi detectada uma incompatibilidade de símbolo pelo vinculador. Esse erro indica que diferentes partes de um aplicativo — isso inclui bibliotecas ou outro código de objeto que contém um link para o aplicativo — usar definições conflitantes do símbolo. O [detectar incompatibilidade](../../preprocessor/detect-mismatch.md) pragma é usado para definir esses símbolos e detectar os valores conflitantes.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Esse erro pode ocorrer quando um arquivo de objeto em seu projeto está desatualizado. Antes de tentar outras soluções para esse erro, execute uma compilação limpa para garantir que os arquivos de objeto atuais.  
  
-   O Visual Studio define os símbolos a seguir para evitar a vinculação de código incompatível, o que pode causar erros de tempo de execução ou outro comportamento inesperado.  
  
     `_MSC_VER`  
     Indica os números de versão primária e secundária do compilador do Visual C++ que é usado para criar um aplicativo ou uma biblioteca. Código que é compilado, usando uma versão do compilador do Visual C++ é incompatível com o código que é compilado, usando uma versão com números de versão principal e secundária diferentes. Para obter mais informações, consulte `_MSC_VER` na [Macros predefinidas](../../preprocessor/predefined-macros.md).  
  
     Se você estiver vinculando a uma biblioteca que não é compatível com a versão do compilador do Visual C++ que você estiver usando, e você não pode adquirir ou criar uma versão compatível da biblioteca, você pode usar uma versão anterior do compilador para compilar seu projeto — basta alterar o **conjunto de ferramentas de plataforma** propriedade do projeto. Para obter mais informações, consulte [como: modificar a estrutura de destino e o conjunto de ferramentas de plataforma](../../build/how-to-modify-the-target-framework-and-platform-toolset.md).  
  
     `_ITERATOR_DEBUG_LEVEL`  
     Indica o nível de segurança e recursos que estão habilitados na biblioteca C++ padrão de depuração. Esses recursos podem alterar a representação de determinados objetos de biblioteca padrão C++ e, portanto, torná-los incompatíveis com aqueles que use a segurança diferentes e recursos de depuração. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../../standard-library/iterator-debug-level.md).  
  
     `RuntimeLibrary`  
     Indica a versão do tempo de execução C e de biblioteca padrão C++ que é usada por um aplicativo ou uma biblioteca. O código que usa uma versão do tempo de execução C ou C++ Standard Library é incompatível com o código que usa uma versão diferente. Para obter mais informações, consulte [/MD, /MT, /LD (usar biblioteca em tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md).  
  
     `_PPLTASKS_WITH_WINRT`  
     Indica que o código que usa o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) está vinculado a objetos compilados usando uma configuração diferente para o [/ZW](../../build/reference/zw-windows-runtime-compilation.md) opção de compilador. (**/ZW** suporta C + + CX.) Código que usa ou depende da PPL deve ser compilado usando o mesmo **/ZW** configuração é usada no restante do aplicativo.  
  
     Verifique se os valores desses símbolos estão consistentes em toda os projetos em sua solução do Visual Studio e também que são consistentes com o código e bibliotecas que se vincula ao seu aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)
