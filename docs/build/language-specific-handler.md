---
title: "Identificador espec&#237;fico da linguagem | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 6503e0cd-2d3a-4330-a925-8bed8c27c2be
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Identificador espec&#237;fico da linguagem
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O endereço relativo do manipulador de linguagem específica está presente no UNWIND\_INFO sempre que os sinalizadores UNW\_FLAG\_EHANDLER ou UNW\_FLAG\_UHANDLER são definidos.  Como descrito na seção anterior, o tratador específico de linguagem é chamado como parte de pesquisa para um manipulador de exceção ou como parte de um desenrolamento.  Tem o protótipo seguir:  
  
```  
typedef EXCEPTION_DISPOSITION (*PEXCEPTION_ROUTINE) (  
    IN PEXCEPTION_RECORD ExceptionRecord,  
    IN ULONG64 EstablisherFrame,  
    IN OUT PCONTEXT ContextRecord,  
    IN OUT PDISPATCHER_CONTEXT DispatcherContext  
);  
```  
  
 **ExceptionRecord** fornece um ponteiro para um registro de exceção, que tem a definição de Win64 padrão.  
  
 **EstablisherFrame** é o endereço de base de alocação de pilha fixa para essa função.  
  
 Os pontos de**ContextRecord** ao contexto de exceção na exceção foi gerada \(nos exemplos de manipulador de exceção\) ou a atual “” desenrolam o contexto \(nos exemplos de manipulador de fim.\)  
  
 Pontos de**DispatcherContext** para o contexto do distribuidor para essa função.  Tem a seguinte definição:  
  
```  
typedef struct _DISPATCHER_CONTEXT {  
    ULONG64 ControlPc;  
    ULONG64 ImageBase;  
    PRUNTIME_FUNCTION FunctionEntry;  
    ULONG64 EstablisherFrame;  
    ULONG64 TargetIp;  
    PCONTEXT ContextRecord;  
    PEXCEPTION_ROUTINE LanguageHandler;  
    PVOID HandlerData;  
} DISPATCHER_CONTEXT, *PDISPATCHER_CONTEXT;  
```  
  
 **ControlPc** é o valor de RASGO dentro dessa função.  Este é um endereço de exceção ou endereço em que o controle à esquerda da função de estabelecer.  Este é o RASGO que será usado para determinar se o controle está dentro de qualquer compilação guardada dentro desta função \(por exemplo, um bloco \_\_try para \_\_try\/\_\_except ou \_\_try\/\_\_finally\).  
  
 **ImageBase** é a base de imagem \(endereço de carregamento\) de módulo que contém essa função, para ser adicionado aos deslocamentos de 32 bits usados na entrada de função e desenrola informações para registrar endereços relacionados.  
  
 **FunctionEntry** fornece um ponteiro a entrada de função de RUNTIME\_FUNCTION que contém a função e desenrola endereços relacionados de imagens base de informações para essa função.  
  
 **EstablisherFrame** é o endereço de base de alocação de pilha fixa para essa função.  
  
 **TargetIp** fornece um endereço de declaração opcional que especifica o endereço de continuação de desenrolamento.  Este endereço é ignorado se **EstablisherFrame** não é especificado.  
  
 Os pontos de**ContextRecord** ao contexto de exceção, para o uso de distribuição de exceção sys\/desenrolam o código.  
  
 Pontos de**LanguageHandler** a rotina de linguagem específica do manipulador de linguagem que é chamada.  
  
 Os pontos de**HandlerData** a dados específicos do idioma de manipulador para este funcionam.  
  
## Consulte também  
 [Tratamento de exceções \(x64\)](../build/exception-handling-x64.md)