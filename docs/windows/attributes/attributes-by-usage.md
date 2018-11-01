---
title: Atributos por uso
ms.custom: index-page
ms.date: 10/02/2018
ms.topic: conceptual
helpviewer_keywords:
- attributes [C++/CLI]
ms.assetid: 8be2de10-b1ff-4ca4-a114-75318408593c
ms.openlocfilehash: 2536309025506ca66d9c4b7cdfbaabf5787945e4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50449355"
---
# <a name="attributes-by-usage"></a>Atributos por uso

Este tópico lista os atributos de acordo com os elementos de linguagem C++ para o qual eles se aplicam.

Se um atributo precede um elemento que não está no escopo do atributo, o bloco de atributo será tratado como um comentário.

|Atributo|Descrição|
|---------------|-----------------|
|[Atributos de módulo](module-attributes.md)|Aplica-se para o [módulo](module-cpp.md) atributo.|
|[Atributos de interface](interface-attributes.md)|Aplica-se para o [interface](../../cpp/interface.md) palavra-chave C++.|
|[Atributos de classe](class-attributes.md)|Aplica-se para a palavra-chave C++.|
|[Atributos de método](method-attributes.md)|Aplica-se aos métodos em uma classe, coclass ou interface.|
|[Atributos de parâmetro](parameter-attributes.md)|Aplica-se aos parâmetros de um método em uma classe ou interface.|
|[Atributos de membro de dados](data-member-attributes.md)|Aplica-se para os membros de dados em uma classe, coclass ou interface.|
|[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)|Aplica-se às palavras-chave C++.|
|[Atributos de matriz](array-attributes.md)|Se aplica a matrizes ou `SAFEARRAY`s.|
|[Atributos independentes](stand-alone-attributes.md)|Atua de forma semelhante uma linha de código, mas não funciona em uma palavra-chave C++. Declarações de atributo autônomo exigem um ponto e vírgula no final da linha.|
|[Atributos personalizados](custom-attributes-cpp.md)|Permite ao usuário estender os metadados.|

## <a name="module-attributes"></a>Atributos de módulo
O seguinte atributo só pode ser aplicado para o [módulo](module-cpp.md) atributo.

|Atributo|Descrição|
|---------------|-----------------|
|[helpstringdll](helpstringdll.md)|Especifica o nome da DLL a usar para executar a pesquisa de cadeia de caracteres do documento (localização).|

## <a name="interface-attributes"></a>Atributos de interface

Os atributos a seguir se aplicam para o [interface (ou interface)](../../cpp/interface.md) palavra-chave C++.

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

[Atributos C++ para COM e .NET](cpp-attributes-com-net.md)<br/>
[Atributos por grupo](attributes-by-group.md)<br/>
[Referência alfabética de atributos](attributes-alphabetical-reference.md)