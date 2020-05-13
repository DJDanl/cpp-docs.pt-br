---
title: Atributos por uso
ms.custom: index-page
ms.date: 10/02/2018
ms.topic: conceptual
helpviewer_keywords:
- attributes [C++/CLI]
ms.assetid: 8be2de10-b1ff-4ca4-a114-75318408593c
ms.openlocfilehash: dcbed019f8cd08ddbf4ab6b4756a59f7fcbabc4b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361331"
---
# <a name="attributes-by-usage"></a>Atributos por uso

Este tópico lista atributos de acordo com os elementos de linguagem C++ aos quais eles se aplicam.

Se um atributo precede ruminar a um elemento que não está no escopo do atributo, o bloco de atributos é tratado como um comentário.

|Atributo|Descrição|
|---------------|-----------------|
|[Atributos de módulo](module-attributes.md)|Aplica-se ao atributo do [módulo.](module-cpp.md)|
|[Atributos de interface](interface-attributes.md)|Aplica-se à [palavra-chave __interface](../../cpp/interface.md) C++.|
|[Atributos de classe](class-attributes.md)|Aplica-se à palavra-chave C++.|
|[Atributos de método](method-attributes.md)|Aplica-se aos métodos em uma classe, coclasse ou interface.|
|[Atributos de parâmetro](parameter-attributes.md)|Aplica-se aos parâmetros de um método em uma classe ou interface.|
|[Atributos de membro de dados](data-member-attributes.md)|Aplica-se aos membros de dados em uma classe, coclasse ou interface.|
|[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)|Aplica-se às palavras-chave C++.|
|[Atributos de matriz](array-attributes.md)|Aplica-se a `SAFEARRAY`matrizes ou s.|
|[Atributos independentes](stand-alone-attributes.md)|Opera mais como uma linha de código, mas não opera em uma palavra-chave C++. As declarações de atributos autônomos requerem um ponto e vírgula no final da linha.|
|[Atributos personalizados](custom-attributes-cpp.md)|Permite que o usuário amplie os metadados.|

## <a name="module-attributes"></a>Atributos de módulo

O atributo a seguir só pode ser aplicado ao atributo do [módulo.](module-cpp.md)

|Atributo|Descrição|
|---------------|-----------------|
|[helpstringdll](helpstringdll.md)|Especifica o nome da DLL a ser usada para executar a pesquisa de seqüência de seqüência sinuosa (localização).|

## <a name="interface-attributes"></a>Atributos de interface

Os atributos a seguir aplicam-se à palavra-chave Interface [(ou __interface)](../../cpp/interface.md) C++.

|Atributo|Descrição|
|---------------|-----------------|
|[async_uuid](async-uuid.md)|Especifica o UUID que direciona o compilador MIDL para definir as versões síncronas e assíncronas de uma interface COM.|
|[Personalizado](custom-cpp.md)|Permite que você defina seus próprios atributos.|
|[dispinterface](dispinterface.md)|Coloca uma interface no arquivo .idl como uma interface de despacho.|
|[Dupla](dual.md)|Coloca uma interface no arquivo .idl como uma interface dupla.|
|[Exportação](export.md)|Faz com que uma estrutura de dados seja colocada no arquivo .idl.|
|[helpcontext](helpcontext.md)|Especifica um ID de contexto que permite ao usuário visualizar informações sobre esse elemento no arquivo Ajuda.|
|[Helpfile](helpfile.md)|Define o nome do arquivo Ajuda para uma biblioteca de tipos.|
|[helpstring](helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[helpstringcontext](helpstringcontext.md)|Especifica o ID de um tópico de ajuda em um arquivo .hlp ou .chm.|
|[helpstringdll](helpstringdll.md)|Especifica o nome da DLL a ser usada para executar a pesquisa de seqüência de seqüência sinuosa (localização).|
|[Escondidos](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[library_block](library-block.md)|Coloca uma construção dentro do bloco de biblioteca do arquivo .idl.|
|[Local](local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, designa um procedimento local para o qual não são gerados stubs.|
|[nonextensible](nonextensible.md)|Especifica que `IDispatch` a implementação inclui apenas as propriedades e métodos listados na descrição da interface e não pode ser estendida com membros adicionais em tempo de execução. Este atributo só é válido em uma interface [dupla.](dual.md)|
|[Odl](odl.md)|Identifica uma interface como uma interface ODL (Object Description Language, linguagem de descrição de objetos).|
|[Objeto](object-cpp.md)|Identifica uma interface personalizada.|
|[oleautomation](oleautomation.md)|Indica que uma interface é compatível com automação.|
|[pointer_default](pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto ponteiros de nível superior que aparecem em listas de parâmetros.|
|[Ptr](ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[Restrito](restricted.md)|Designa quais membros da biblioteca não podem ser chamados arbitrariamente.|
|[uuid](uuid-cpp-attributes.md)|Fornece o ID exclusivo para a biblioteca|

Você deve observar essas regras para definir uma interface:

- A convenção de chamada padrão é [__stdcall](../../cpp/stdcall.md).

- Um GUID é fornecido para você se você não fornecer um.

- Não são permitidos métodos sobrecarregados.

Ao não especificar o atributo [uuid](uuid-cpp-attributes.md) e usar o mesmo nome de interface em diferentes projetos de atributos, o mesmo GUID é gerado.

## <a name="see-also"></a>Confira também

[Atributos C++ para COM e .NET](cpp-attributes-com-net.md)<br/>
[Atributos por grupo](attributes-by-group.md)<br/>
[Referência alfabética de atributos](attributes-alphabetical-reference.md)
