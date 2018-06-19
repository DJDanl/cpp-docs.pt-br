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
- attributes [C++], reference topics
- interface attributes
ms.assetid: 27fcdfee-abce-4585-8b53-ee31635356e8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6f57cdce20a54b8bc56b804e12f59f92855c7f69
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33880199"
---
# <a name="interface-attributes"></a>Atributos de interface
Os atributos a seguir se aplicam ao [interface (ou interface)](../cpp/interface.md) palavra-chave do C++.  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|[async_uuid](../windows/async-uuid.md)|Especifica o UUID que instrui o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.|  
|[custom](../windows/custom-cpp.md)|Permite que você definir seus próprios atributos.|  
|[dispinterface](../windows/dispinterface.md)|Coloca uma interface no arquivo. idl como uma interface de expedição.|  
|[dual](../windows/dual.md)|Coloca uma interface no arquivo. idl como uma interface dupla.|  
|[export](../windows/export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|  
|[helpcontext](../windows/helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre este elemento no arquivo de Ajuda.|  
|[helpfile](../windows/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|  
|[helpstring](../windows/helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual se aplica.|  
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID de um tópico da Ajuda em um arquivo. hlp ou. chm.|  
|[helpstringdll](../windows/helpstringdll.md)|Especifica o nome da DLL a ser usado para executar a pesquisa de cadeia de caracteres do documento (localização).|  
|[hidden](../windows/hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|  
|[library_block](../windows/library-block.md)|Coloca uma construção dentro do bloco de biblioteca do arquivo. idl.|  
|[local](../windows/local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usada em uma função individual, designa um procedimento de local para o qual nenhuma stubs são gerados.|  
|[nonextensible](../windows/nonextensible.md)|Especifica que o `IDispatch` implementação inclui apenas as propriedades e métodos listados na descrição de interface e não podem ser estendidos com membros adicionais em tempo de execução. Esse atributo só é válido em uma [dual](../windows/dual.md) interface.|  
|[odl](../windows/odl.md)|Identifica uma interface como uma interface de linguagem de descrição do objeto (ODL).|  
|[object](../windows/object-cpp.md)|Identifica uma interface personalizada.|  
|[oleautomation](../windows/oleautomation.md)|Indica que uma interface compatível com automação.|  
|[pointer_default](../windows/pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros exceto ponteiros de nível superior que aparecem em listas de parâmetros.|  
|[ptr](../windows/ptr.md)|Designa um ponteiro como um ponteiro completo.|  
|[restricted](../windows/restricted.md)|Designa quais membros da biblioteca não podem ser chamados arbitrariamente.|  
|[uuid](../windows/uuid-cpp-attributes.md)|Fornece a ID exclusiva para a biblioteca|  
  
 Você deve observar estas regras para definir uma interface:  
  
-   Convenção de chamada padrão é [stdcall](../cpp/stdcall.md).  
  
-   Um GUID é fornecido para você, se você não fornecer um.  
  
-   Não há métodos sobrecarregados são permitidos.  
  
 Ao não especificar o [uuid](../windows/uuid-cpp-attributes.md) de atributos e usar o mesmo nome da interface em projetos de atributo diferente, o mesmo GUID é gerado.  
  
## <a name="see-also"></a>Consulte também  
 [Atributos por uso](../windows/attributes-by-usage.md)