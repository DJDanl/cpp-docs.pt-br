---
title: "Classe ios_base | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ios_base"
  - "std.ios_base"
  - "std::ios_base"
  - "xiosbase/std::ios_base"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ios_base"
ms.assetid: 0f9e0abc-f70f-49bc-aa1f-003859f56cfe
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe ios_base
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe descreve o armazenamento e funções de membro fluxos comuns a entrada e saída que não dependem dos parâmetros do modelo.  \(A classe de modelo[basic\_ios](../Topic/basic_ios%20Class.md)descreve o que é comum e depende de parâmetros de modelo.\)  
  
 Um objeto da classe ios\_base armazena informações de formatação, que consiste em:  
  
-   Formatar sinalizadores em um objeto do tipo[fmtflags](../Topic/ios_base::fmtflags.md).  
  
-   Uma máscara de exceção em um objeto do tipo[iostate](../Topic/ios_base::iostate.md).  
  
-   Uma largura de campo em um objeto do tipo`int`*.*  
  
-   Uma precisão de exibição em um objeto do tipo`int`.  
  
-   Um objeto de localidade em um objeto do tipo**localidade**.  
  
-   Duas matrizes extensíveis, com elementos do tipo**longo**e`void`ponteiro.  
  
 Um objeto da classe ios\_base também armazena informações de estado de fluxo em um objeto do tipo[iostate](../Topic/ios_base::iostate.md)e uma pilha de retorno de chamada.  
  
### Construtores  
  
|||  
|-|-|  
|[ios\_base](../Topic/ios_base::ios_base.md)|Constrói`ios_base`objetos.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[event\_callback](../Topic/ios_base::event_callback.md)|Descreve uma função passada para[register\_call](../Topic/ios_base::register_callback.md).|  
|[fmtflags](../Topic/ios_base::fmtflags.md)|Constantes para especificar a aparência da saída.|  
|[iostate](../Topic/ios_base::iostate.md)|Define constantes que descreve o estado de um fluxo.|  
|[OpenMode](../Topic/ios_base::openmode.md)|Descreve como interagir com um fluxo.|  
|[seekdir](../Topic/ios_base::seekdir.md)|Especifica o ponto de partida para operações de deslocamento.|  
  
### Enumerações  
  
|||  
|-|-|  
|[evento](../Topic/ios_base::event.md)|Especifica os tipos de evento.|  
  
### Constantes  
  
|||  
|-|-|  
|[adjustfield](../Topic/ios_base::fmtflags.md)|Uma máscara de bits definida como`internal` &#124; `left` &#124; `right`.|  
|[aplicativo](../Topic/ios_base::openmode.md)|Especifica a busca até o final de um fluxo antes de cada inserção.|  
|[comeu](../Topic/ios_base::openmode.md)|Especifica a busca até o final de um fluxo quando seu objeto de controle é criado.|  
|[badbit](../Topic/ios_base::iostate.md)|Registra a perda de integridade de buffer de fluxo.|  
|[BaseField](../Topic/ios_base::fmtflags.md)|Uma máscara de bits definida como`dec` &#124; `hex` &#124; `oct`.|  
|[começa](../Topic/ios_base::seekdir.md)|Especifica que buscam em relação ao início de uma sequência.|  
|[binário](../Topic/ios_base::openmode.md)|Especifica que um arquivo deve ser lido como um fluxo binário, em vez de um fluxo de texto.|  
|[boolalpha](../Topic/ios_base::fmtflags.md)|Especifica a inserção ou extração de objetos do tipo`bool`como nomes \(tais como`true`e`false`\), e não como valores numéricos.|  
|[Repetir](../Topic/ios_base::seekdir.md)|Especifica que buscam em relação à posição atual em uma seqüência.|  
|[dec](../Topic/ios_base::fmtflags.md)|Especifica a inserção ou extração de valores inteiros em formato decimal.|  
|[end](../Topic/ios_base::seekdir.md)|Especifica que buscam em relação ao final de uma seqüência.|  
|[eofbit](../Topic/ios_base::iostate.md)|Registros final do arquivo durante a extração de um fluxo.|  
|[failbit](../Topic/ios_base::iostate.md)|Registra uma falha ao extrair um campo válido a partir de um fluxo.|  
|[fixo](../Topic/ios_base::fmtflags.md)|Especifica a inserção de valores de ponto flutuante em formato de ponto fixo \(com nenhum campo expoente\).|  
|[floatfield](../Topic/ios_base::fmtflags.md)|Uma máscara de bits definida como`fixed` &#124; `scientific`|  
|[goodbit](../Topic/ios_base::iostate.md)|Desmarque todos os bits de estado.|  
|[hex](../Topic/ios_base::fmtflags.md)|Especifica a inserção ou extração de valores inteiros em formato hexadecimal.|  
|[em](../Topic/ios_base::openmode.md)|Especifica a extração de um fluxo.|  
|[interno](../Topic/ios_base::fmtflags.md)|Preenche uma largura de campo inserindo caracteres de preenchimento em um ponto interno para um campo numérico gerado.|  
|[esquerda](../Topic/ios_base::fmtflags.md)|Especifica a justificação à esquerda.|  
|[oct](../Topic/ios_base::fmtflags.md)|Especifica a inserção ou extração de valores inteiros em formato octal.|  
|[saída](../Topic/ios_base::openmode.md)|Especifica a inserção em um fluxo.|  
|[direita](../Topic/ios_base::fmtflags.md)|Especifica a justificação à direita.|  
|[científica](../Topic/ios_base::fmtflags.md)|Especifica a inserção de valores de ponto flutuante em formato científico \(com um campo de expoente\).|  
|[showbase](../Topic/ios_base::fmtflags.md)|Especifica a inserção de um prefixo que revela a base de um campo inteiro gerado.|  
|[showpoint](../Topic/ios_base::fmtflags.md)|Especifica a inserção incondicional de um ponto decimal em um campo de ponto flutuante gerado.|  
|[showpos](../Topic/ios_base::fmtflags.md)|Especifica a inserção de um sinal de adição em um campo numérico gerado de não negativo.|  
|[skipws](../Topic/ios_base::fmtflags.md)|Especifica a ignorar espaço em branco antes de determinados extrações.|  
|[Truncar](../Topic/ios_base::openmode.md)|Especifica excluir conteúdo de um arquivo existente ao seu objeto de controle é criado.|  
|[unitbuf](../Topic/ios_base::fmtflags.md)|Causas de saída a serem liberadas após cada inserção.|  
|[maiúscula](../Topic/ios_base::fmtflags.md)|Especifica a inserção de equivalentes maiúsculas de minúsculas em determinados inserções.|  
  
### Funções membro  
  
|||  
|-|-|  
|[falha](../Topic/ios_base::failure.md)|A classe de membro serve como a classe base para todas as exceções geradas pela função de membro[Limpar](../Topic/basic_ios::clear.md)na classe de modelo[basic\_ios](../Topic/basic_ios%20Class.md).|  
|[sinalizadores](../Topic/ios_base::flags.md)|Define ou retorna as configurações atuais do sinalizador.|  
|[getloc](../Topic/ios_base::getloc.md)|Retorna o objeto de localidade armazenado.|  
|[imbue](../Topic/ios_base::imbue.md)|Altera a localidade.|  
|[Init](../Topic/ios_base::Init.md)|Cria os objetos iostream padrão quando construída.|  
|[iword](../Topic/ios_base::iword.md)|Atribui um valor a ser armazenado como um`iword`.|  
|[precisão](../Topic/ios_base::precision.md)|Especifica o número de dígitos a serem exibidos em um número de ponto flutuante.|  
|[pword](../Topic/ios_base::pword.md)|Atribui um valor a ser armazenado como um`pword`.|  
|[register\_callback](../Topic/ios_base::register_callback.md)|Especifica uma função de retorno de chamada.|  
|[SETF](../Topic/ios_base::setf.md)|Define os sinalizadores especificados.|  
|[sync\_with\_stdio](../Topic/ios_base::sync_with_stdio.md)|Garante que iostream e operações da biblioteca de tempo de execução C ocorrerem na ordem em que aparecem no código\-fonte.|  
|[unsetf](../Topic/ios_base::unsetf.md)|Faz com que os sinalizadores especificados ficar inativo.|  
|[largura](../Topic/ios_base::width.md)|Define o comprimento do fluxo de saída.|  
|[xalloc](../Topic/ios_base::xalloc.md)|Especifica que uma variável deve ser parte do fluxo.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/ios_base::operator=.md)|O operador de atribuição de`ios_base`objetos.|  
  
## Requisitos  
 **Cabeçalho:** \<ios\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)