---
title: Atributos de interface (COM C++)
ms.date: 10/02/2018
helpviewer_keywords:
- attributes [C++/CLI], reference topics
- interface attributes
ms.assetid: 27fcdfee-abce-4585-8b53-ee31635356e8
ms.openlocfilehash: 8218ccb66c6be9edef5d7de751a73bf4753d069f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62409311"
---
# <a name="interface-attributes"></a>Atributos de interface

Os atributos a seguir se aplicam para o [interface (ou interface)](../../cpp/interface.md) C++ palavra-chave.

|Atributo|Descrição|
|---------------|-----------------|
|[async_uuid](async-uuid.md)|Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.|
|[custom](custom-cpp.md)|Permite definir seus próprios atributos.|
|[dispinterface](dispinterface.md)|Coloca uma interface no arquivo. idl como uma interface de expedição.|
|[dual](dual.md)|Coloca uma interface no arquivo. idl como uma interface dupla.|
|[export](export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre esse elemento no arquivo de Ajuda.|
|[helpfile](helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstring](helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[helpstringcontext](helpstringcontext.md)|Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.|
|[helpstringdll](helpstringdll.md)|Especifica o nome da DLL a usar para executar a pesquisa de cadeia de caracteres do documento (localização).|
|[hidden](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[library_block](library-block.md)|Coloca uma construção de dentro do bloco de biblioteca do arquivo. idl.|
|[local](local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, designa um procedimento de local para o qual nenhuma stubs são gerados.|
|[nonextensible](nonextensible.md)|Especifica que o `IDispatch` implementação inclui apenas as propriedades e os métodos listados na descrição da interface e não podem ser estendidos com membros adicionais em tempo de execução. Esse atributo só é válido em uma [dual](dual.md) interface.|
|[odl](odl.md)|Identifica uma interface como uma interface de linguagem de descrição do objeto (ODL).|
|[object](object-cpp.md)|Identifica uma interface personalizada.|
|[oleautomation](oleautomation.md)|Indica que uma interface é compatível com a automação.|
|[pointer_default](pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto ponteiros de nível superior que aparecem em listas de parâmetros.|
|[ptr](ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[restricted](restricted.md)|Designa quais membros da biblioteca não podem ser chamados arbitrariamente.|
|[uuid](uuid-cpp-attributes.md)|Fornece a ID exclusiva para a biblioteca|

Você deve observar estas regras para definir uma interface:

- Convenção de chamada padrão é [stdcall](../../cpp/stdcall.md).

- Um GUID é fornecido para você, se você não fornecer um.

- Não há métodos sobrecarregados são permitidos.

Ao não especificar o [uuid](uuid-cpp-attributes.md) de atributo e usando o mesmo nome de interface em projetos de atributo diferente, o mesmo GUID é gerado.

## <a name="see-also"></a>Consulte também

[Atributos por uso](attributes-by-usage.md)