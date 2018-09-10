---
title: Atributos de interface | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++/CLI], reference topics
- interface attributes
ms.assetid: 27fcdfee-abce-4585-8b53-ee31635356e8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 850646e2dda1f226eff7c921dd3fe9f85595ca69
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44317648"
---
# <a name="interface-attributes"></a>Atributos de interface

Os atributos a seguir se aplicam para o [interface (ou interface)](../cpp/interface.md) palavra-chave C++.

|Atributo|Descrição|
|---------------|-----------------|
|[async_uuid](../windows/async-uuid.md)|Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.|
|[custom](../windows/custom-cpp.md)|Permite definir seus próprios atributos.|
|[dispinterface](../windows/dispinterface.md)|Coloca uma interface no arquivo. idl como uma interface de expedição.|
|[dual](../windows/dual.md)|Coloca uma interface no arquivo. idl como uma interface dupla.|
|[export](../windows/export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|
|[helpcontext](../windows/helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre esse elemento no arquivo de Ajuda.|
|[helpfile](../windows/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstring](../windows/helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.|
|[helpstringdll](../windows/helpstringdll.md)|Especifica o nome da DLL a usar para executar a pesquisa de cadeia de caracteres do documento (localização).|
|[hidden](../windows/hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[library_block](../windows/library-block.md)|Coloca uma construção de dentro do bloco de biblioteca do arquivo. idl.|
|[local](../windows/local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, designa um procedimento de local para o qual nenhuma stubs são gerados.|
|[nonextensible](../windows/nonextensible.md)|Especifica que o `IDispatch` implementação inclui apenas as propriedades e os métodos listados na descrição da interface e não podem ser estendidos com membros adicionais em tempo de execução. Esse atributo só é válido em uma [dual](../windows/dual.md) interface.|
|[odl](../windows/odl.md)|Identifica uma interface como uma interface de linguagem de descrição do objeto (ODL).|
|[object](../windows/object-cpp.md)|Identifica uma interface personalizada.|
|[oleautomation](../windows/oleautomation.md)|Indica que uma interface é compatível com a automação.|
|[pointer_default](../windows/pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto ponteiros de nível superior que aparecem em listas de parâmetros.|
|[ptr](../windows/ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[restricted](../windows/restricted.md)|Designa quais membros da biblioteca não podem ser chamados arbitrariamente.|
|[uuid](../windows/uuid-cpp-attributes.md)|Fornece a ID exclusiva para a biblioteca|

Você deve observar estas regras para definir uma interface:

- Convenção de chamada padrão é [stdcall](../cpp/stdcall.md).

- Um GUID é fornecido para você, se você não fornecer um.

- Não há métodos sobrecarregados são permitidos.

Ao não especificar o [uuid](../windows/uuid-cpp-attributes.md) de atributo e usando o mesmo nome de interface em projetos de atributo diferente, o mesmo GUID é gerado.

## <a name="see-also"></a>Consulte também

[Atributos por uso](../windows/attributes-by-usage.md)