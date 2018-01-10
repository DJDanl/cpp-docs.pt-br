---
title: "Identificador específico da linguagem | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 6503e0cd-2d3a-4330-a925-8bed8c27c2be
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: dc15e730666a643dfaa028fe7bc6166144897308
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="language-specific-handler"></a>Identificador específico da linguagem
O endereço relativo do manipulador específico de idioma está presente no UNWIND_INFO sempre que UNW_FLAG_EHANDLER ou UNW_FLAG_UHANDLER estão definidos. Conforme descrito na seção anterior, o identificador específico da linguagem é chamado como parte da pesquisa para um manipulador de exceção ou como parte de uma liberação. Ele tem o seguinte protótipo:  
  
```  
typedef EXCEPTION_DISPOSITION (*PEXCEPTION_ROUTINE) (  
    IN PEXCEPTION_RECORD ExceptionRecord,  
    IN ULONG64 EstablisherFrame,  
    IN OUT PCONTEXT ContextRecord,  
    IN OUT PDISPATCHER_CONTEXT DispatcherContext  
);  
```  
  
 **ExceptionRecord** fornece um ponteiro para um registro de exceções, que tem a definição padrão de Win64.  
  
 **EstablisherFrame** é o endereço de base da alocação da pilha fixa para esta função.  
  
 **ContextRecord** aponta para o contexto de exceção na hora em que a exceção foi gerada (no caso de manipulador de exceção) ou atual "Voltar" contexto (no caso de manipulador de término).  
  
 **DispatcherContext** aponta para o contexto de dispatcher para essa função. Ele tem a seguinte definição:  
  
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
  
 **ControlPc** é o valor de RIP nessa função. Este é um endereço de exceção ou o endereço em que o controle foi a função estabelecer. Este é o RIP que será usado para determinar se o controle está dentro de alguns construção protegida nessa função (por exemplo, um bloco de Try para \__try /\__except ou \__try /\__finally).  
  
 **ImageBase** é a imagem base (endereço de carregamento) do módulo que contém essa função, para ser adicionado aos deslocamentos de 32 bits usados na entrada de função e informações para registrar os endereços relativos de desenrolamento.  
  
 **FunctionEntry** fornece um ponteiro para o RUNTIME_FUNCTION entrada mantém a função de função e liberar endereços relativos de imagem base de informações para esta função.  
  
 **EstablisherFrame** é o endereço de base da alocação da pilha fixa para esta função.  
  
 **TargetIp** fornece um endereço de instrução opcional que especifica o endereço de continuação do desenrolamento. Esse endereço será ignorado se **EstablisherFrame** não for especificado.  
  
 **ContextRecord** aponta para o contexto de exceção para uso por código de expedição/desenrolamento de exceção do sistema.  
  
 **LanguageHandler** aponta para a rotina de manipulador de idioma específico do idioma que está sendo chamada.  
  
 **HandlerData** aponta para os dados específicos de linguagem manipulador para essa função.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceção (x64)](../build/exception-handling-x64.md)