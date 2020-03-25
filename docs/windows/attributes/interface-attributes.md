---
title: Atributos de interfaceC++ (com)
ms.date: 10/02/2018
helpviewer_keywords:
- attributes [C++/CLI], reference topics
- interface attributes
ms.assetid: 27fcdfee-abce-4585-8b53-ee31635356e8
ms.openlocfilehash: 81a88ddfd74f20fa57ef615c988ba9786f41c1ad
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214819"
---
# <a name="interface-attributes"></a>Atributos de interface

Os atributos a seguir se aplicam à palavra-chave [interface (ou __interface)](../../cpp/interface.md) C++ .

|Atributo|DESCRIÇÃO|
|---------------|-----------------|
|[async_uuid](async-uuid.md)|Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.|
|[custom](custom-cpp.md)|Permite que você defina seus próprios atributos.|
|[dispinterface](dispinterface.md)|Coloca uma interface no arquivo. idl como uma interface de expedição.|
|[dual](dual.md)|Coloca uma interface no arquivo. idl como uma interface dupla.|
|[export](export.md)|Faz com que uma estrutura de dados seja colocada no arquivo. idl.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite ao usuário exibir informações sobre esse elemento no arquivo de ajuda.|
|[helpfile](helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstring](helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[helpstringcontext](helpstringcontext.md)|Especifica a ID de um tópico da ajuda em um arquivo. hlp ou. chm.|
|[helpstringdll](helpstringdll.md)|Especifica o nome da DLL a ser usada para executar a pesquisa de cadeia de caracteres do documento (localização).|
|[hidden](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[library_block](library-block.md)|Coloca uma construção dentro do bloco de biblioteca do arquivo. idl.|
|[local](local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, o designa um procedimento local para o qual nenhum stub é gerado.|
|[nonextensible](nonextensible.md)|Especifica que a implementação de `IDispatch` inclui apenas as propriedades e os métodos listados na descrição da interface e não pode ser estendido com membros adicionais em tempo de execução. Esse atributo só é válido em uma interface [dupla](dual.md) .|
|[odl](odl.md)|Identifica uma interface como uma interface de linguagem de descrição de objeto (ODL).|
|[object](object-cpp.md)|Identifica uma interface personalizada.|
|[oleautomation](oleautomation.md)|Indica que uma interface é compatível com a automação.|
|[pointer_default](pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto para os ponteiros de nível superior que aparecem nas listas de parâmetros.|
|[ptr](ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[restricted](restricted.md)|Designa quais membros da biblioteca não podem ser chamados arbitrariamente.|
|[uuid](uuid-cpp-attributes.md)|Fornece a ID exclusiva para a biblioteca|

Você deve observar essas regras para definir uma interface:

- A Convenção de chamada padrão é [__stdcall](../../cpp/stdcall.md).

- Um GUID será fornecido para você se você não fornecer um.

- Nenhum método sobrecarregado é permitido.

Quando não especificar o atributo [UUID](uuid-cpp-attributes.md) e usar o mesmo nome de interface em projetos de atributo diferentes, o mesmo GUID será gerado.

## <a name="see-also"></a>Confira também

[Atributos por uso](attributes-by-usage.md)
