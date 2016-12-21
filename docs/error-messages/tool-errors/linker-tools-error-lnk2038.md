---
title: "Erro das Ferramentas de Vinculador LNK2038 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK2038"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2038"
ms.assetid: b8d0fb35-eee6-4f52-b3c4-239cb4f65656
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2038
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

incompatibilidade detectada para '\<nome\>': valor '\<valor 1\>' não corresponde ao valor '\<valor 2\>' em \<filename.obj\>  
  
 Foi detectada uma incompatibilidade de símbolo pelo vinculador.  Esse erro indica que as diferentes partes de um aplicativo, isso inclui bibliotecas ou outro código de objeto ao qual o aplicativo se vincula, usam definições conflitantes do símbolo.  O pragma [detect mismatch](../../preprocessor/detect-mismatch.md) é usado para definir esses símbolos e para detectar seus valores conflitante.  
  
### Para corrigir este erro  
  
-   Esse erro pode ocorrer quando um arquivo de objeto no seu projeto está desatualizado.  Antes que tentar outras soluções para esse erro, execute uma compilação limpa para garantir que os arquivos de objeto sejam atuais.  
  
-   O Visual Studio define os seguintes símbolos para evitar vincular códigos incompatíveis, que podem causar erros em tempo de execução ou outro comportamento inesperado.  
  
     `_MSC_VER`  
     Indica os números das versões primária e secundária do compilador do Visual C\+\+ que é usado para compilar um aplicativo ou uma biblioteca.  O código que é compilado usando uma versão do compilador do Visual C\+\+ não é compatível com o código compilado com uma versão que tenha diferentes números de versão principal e secundário.  Para obter mais informações, consulte `_MSC_VER` em [Macros predefinidas](../../preprocessor/predefined-macros.md).  
  
     Se você estiver vinculando a uma biblioteca que não é compatível com a versão do compilador do Visual C\+\+ que você está usando, e você não puder adquirir ou compilar uma versão compatível de biblioteca, você poderá usar uma versão anterior do compilador para compilar seu projeto, basta alterar a propriedade de **Conjunto de ferramentas da plataforma** do projeto.  Para obter mais informações, consulte [Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../../build/how-to-modify-the-target-framework-and-platform-toolset.md).  
  
     `_ITERATOR_DEBUG_LEVEL`  
     Indica o nível dos recursos de segurança e de depuração que estão ativados na biblioteca padrão de C\+\+.  Esses recursos podem alterar a representação de determinados objetos da Biblioteca Padrão do C\+\+ e, assim, torná\-los incompatíveis com aqueles que usam recursos diferentes de segurança e depuração.  Para obter mais informações, consulte [\_ITERATOR\_DEBUG\_LEVEL](../../standard-library/iterator-debug-level.md).  
  
     `RuntimeLibrary`  
     Indica a versão do tempo de execução de C e da biblioteca padrão de C\+\+ que é usada por um aplicativo ou por uma biblioteca.  O código que usa uma versão do tempo de execução padrão C ou da Biblioteca padrão do C\+\+ não é compatível com o código que usa uma versão diferente.  Para obter mais informações, consulte [\/MD, \/MT, \/LD \(usar biblioteca em tempo de execução\)](../../build/reference/md-mt-ld-use-run-time-library.md).  
  
     `_PPLTASKS_WITH_WINRT`  
     Indica que esse código que usa [A paralela da biblioteca \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md) está vinculado a objetos criados usando uma configuração diferente para a opção de compilador de [\/ZW](../../build/reference/zw-windows-runtime-compilation.md) . \(suporte C\+\+\/CX de**\/ZW** .\) O código que usa ou depende de PPL deve ser criado usando a mesma configuração de **\/ZW** que é usado no restante do aplicativo.  
  
     Certifique\-se de que os valores desses símbolos sejam consistentes em todos os projetos na solução do Visual Studio, e que também sejam consistentes com o código e as bibliotecas com os quais seu aplicativo é vinculado.  
  
## Consulte também  
 [Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)