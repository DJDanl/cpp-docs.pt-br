---
title: Identificador específico da linguagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 6503e0cd-2d3a-4330-a925-8bed8c27c2be
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 678f5695523751ebc1ef3c5dba2b63154b21833c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45714942"
---
# <a name="language-specific-handler"></a>Identificador específico da linguagem

O endereço relativo do manipulador específico de linguagem está presente no UNWIND_INFO sempre que os sinalizadores UNW_FLAG_EHANDLER ou UNW_FLAG_UHANDLER são definidos. Conforme descrito na seção anterior, o identificador específico da linguagem é chamado como parte da pesquisa para um manipulador de exceção ou como parte de um desenrolamento. Ele tem o seguinte protótipo:

```
typedef EXCEPTION_DISPOSITION (*PEXCEPTION_ROUTINE) (
    IN PEXCEPTION_RECORD ExceptionRecord,
    IN ULONG64 EstablisherFrame,
    IN OUT PCONTEXT ContextRecord,
    IN OUT PDISPATCHER_CONTEXT DispatcherContext
);
```

**ExceptionRecord** fornece um ponteiro para um registro de exceção, que contém a definição padrão do Win64.

**EstablisherFrame** é o endereço da base de alocação fixa de pilha para essa função.

**ContextRecord** aponta para o contexto de exceção na hora em que a exceção foi gerada (no caso do manipulador de exceção) ou atual "desenrolar" contexto (no caso de manipulador de término).

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

**ControlPc** é o valor de RIP dentro dessa função. Isso é um endereço de exceção ou o endereço no qual o controle ficaria a função estabelecer. Esse é o RIP que será usado para determinar se o controle está dentro de alguns constructo protegido dentro dessa função (por exemplo, um bloco de Try para \__try /\_EXCEPT ou \__try /\__finally).

**ImageBase** é a imagem base (endereço de carregamento) do módulo que contém essa função, a serem adicionados aos deslocamentos de 32 bits usados na entrada de função e informações para registrar endereços relativos de desenrolamento.

**FunctionEntry** fornece um ponteiro para o RUNTIME_FUNCTION que contém a função de entrada de função e endereços relativos de imagem base de informações para essa função de desenrolamento.

**EstablisherFrame** é o endereço da base de alocação fixa de pilha para essa função.

**TargetIp** fornece um endereço de instrução opcional que especifica o endereço de continuação do desenrolamento. Esse endereço será ignorado se **EstablisherFrame** não for especificado.

**ContextRecord** aponta para o contexto de exceção, para uso pelo código de expedição/desenrolamento de exceção do sistema.

**LanguageHandler** aponta para a rotina do manipulador de linguagem específica do idioma que está sendo chamada.

**HandlerData** aponta para os dados de manipulador de idioma específico para essa função.

## <a name="see-also"></a>Consulte também

[Tratamento de exceção (x64)](../build/exception-handling-x64.md)