---
title: Atributos de compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- cl.exe compiler, attributes
- attributes [C++/CLI], compiler
ms.assetid: 53cd9bee-1521-48ec-b171-80feac2096cc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1c1ce698992f1f34434a476be83da6f4697f619c
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44316530"
---
# <a name="compiler-attributes"></a>Atributos de compilador

Os atributos de compilador fornecem uma variedade de funcionalidades.

|Atributo|Descrição|
|---------------|-----------------|
|[emitidl](../windows/emitidl.md)|Determina se todos os atributos IDL subsequentes serão processados e colocados no arquivo. idl gerado.|
|[event_receiver](../windows/event-receiver.md)|Cria um receptor de eventos.|
|[event_source](../windows/event-source.md)|Cria uma origem de evento.|
|[export](../windows/export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|
|[Implementa](../windows/implements-cpp.md)|Especifica as interfaces de distribuição que são forçadas para serem membros da coclass IDL.|
|[importidl](../windows/importidl.md)|Insere o arquivo. idl especificado no arquivo. idl gerado.|
|[importlib](../windows/importlib.md)|Torna os tipos que já foram compilados em outra biblioteca de tipos disponível para a biblioteca de tipos que está sendo criada.|
|[includelib](../windows/includelib-cpp.md)|Faz com que um arquivo. IDL ou. h a serem incluídos no arquivo. idl gerado.|
|[library_block](../windows/library-block.md)|Coloca uma construção de dentro do bloco de biblioteca do arquivo. idl.|
|[no_injected_text](../windows/no-injected-text.md)|Impede que o compilador injetando código como resultado do uso do atributo.|
|[satype](../windows/satype.md)|Especifica o tipo de dados a `SAFEARRAY`.|
|[version](../windows/version-cpp.md)|Identifica uma versão específica entre várias versões de uma interface ou classe.|

## <a name="see-also"></a>Consulte também

[Atributos por grupo](../windows/attributes-by-group.md)