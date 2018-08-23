---
title: Atributos IDL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++], reference topics
- IDL attributes
- .idl files, attributes
- IDL files, attributes
- .idl files
ms.assetid: 04c596f4-c97b-4952-8053-316678b1d0b6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e084064db598c651865ab671256fa82d54332910
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42607680"
---
# <a name="idl-attributes"></a>Atributos IDL

Tradicionalmente, a manutenção de um arquivo. idl significava que você tinha que:

- Estar familiarizado com a estrutura e sintaxe de um arquivo. idl possam modificá-lo.

- Contar com um assistente, o que permitiria que você modifique alguns aspectos do arquivo. idl.

Agora, você pode modificar o arquivo. idl de dentro de um arquivo de código de origem usando atributos de IDL do Visual C++. Em muitos casos, os atributos de IDL do Visual C++ têm o mesmo nome como atributos MIDL. Quando o nome de um atributo de IDL do Visual C++ e um atributo MIDL forem iguais, isso significa que a colocar o atributo do Visual C++ no arquivo de código fonte resultará em um arquivo. IDL que contém seu atributo MIDL por homônimo. No entanto, um atributo de IDL do Visual C++ não pode fornecer toda a funcionalidade de um atributo MIDL.

Quando não é usado com [atributos COM](../windows/com-attributes.md), atributos de IDL permitem que você defina interfaces. Quando o código-fonte é compilado, os atributos são usados para definir o arquivo. idl gerado. Quando usado com atributos de COM em um projeto ATL, alguns IDL atributos, como `coclass`, fazer com que o código seja injetada no projeto.

Observe que [idl_quote](../windows/idl-quote.md) permite que você use construções MIDL que não têm suporte na versão atual do Visual C++. Isso e outros atributos, como [importlib](../windows/importlib.md) e [includelib](../windows/includelib-cpp.md) ajudam você a usar arquivos. idl existentes em seu projeto atual do Visual C++.

|Atributo|Descrição|
|---------------|-----------------|
|[aggregatable](../windows/aggregatable.md)|Indica se um controle pode ser agregado por outro controle.|
|[appobject](../windows/appobject.md)|Identifica a coclass como um objeto de aplicativo, que é associado um aplicativo completo do EXE e indica que as funções e propriedades da coclass estão globalmente disponíveis na biblioteca de tipo.|
|[async_uuid](../windows/async-uuid.md)|Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.|
|[bindable](../windows/bindable.md)|Indica que a propriedade dá suporte à associação de dados.|
|[call_as](../windows/call-as.md)|Permite que uma função nonremotable a ser mapeada para uma função remota.|
|[case](../windows/case-cpp.md)|Usado com o [switch_type](../windows/switch-type.md) atributo em uma união.|
|[coclass](../windows/coclass.md)|Locais de definição em um arquivo. idl como coclass de classe.|
|[control](../windows/control.md)|Especifica que o tipo definido pelo usuário é um controle.|
|[cpp_quote](../windows/cpp-quote.md)|Emite a cadeia de caracteres especificada, sem caracteres de aspas, para o arquivo de cabeçalho gerado.|
|[defaultbind](../windows/defaultbind.md)|Indica a única propriedade associável que melhor representa o objeto.|
|[defaultcollelem](../windows/defaultcollelem.md)|Usada para otimização de código do Visual Basic.|
|[defaultvalue](../windows/defaultvalue.md)|Permite a especificação de um valor padrão para um parâmetro opcional tipado.|
|[default](../windows/default-cpp.md)|Indica que o personalizado ou dispinterface definido dentro de uma coclass representa a interface de programação padrão.|
|[defaultvtable](../windows/defaultvtable.md)|Define uma interface como a interface de vtable padrão para um controle.|
|[dispinterface](../windows/dispinterface.md)|Coloca uma interface no arquivo. idl como uma interface de expedição.|
|[displaybind](../windows/displaybind.md)|Indica uma propriedade que deve ser exibida para o usuário como associável.|
|[dual](../windows/dual.md)|Coloca uma interface no arquivo. idl como uma interface dupla.|
|[entry](../windows/entry.md)|Especifica uma constante ou uma função exportada em um módulo, identificando o ponto de entrada na DLL.|
|[first_is](../windows/first-is.md)|Especifica o índice do primeiro elemento da matriz a ser transmitido.|
|[helpcontext](../windows/helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre esse elemento no arquivo de Ajuda.|
|[helpfile](../windows/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.|
|[helpstringdll](../windows/helpstringdll.md)|Especifica o nome da DLL a usar para executar a pesquisa de cadeia de caracteres do documento (localização).|
|[helpstring](../windows/helpstring.md)|Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.|
|[hidden](../windows/hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[idl_module](../windows/idl-module.md)|Especifica um ponto de entrada em uma DLL.|
|[idl_quote](../windows/idl-quote.md)|Permite que você use atributos ou IDL construções que não são suportados na versão atual do Visual C++.|
|[id](../windows/id.md)|Especifica um DISPID para uma função de membro (uma propriedade ou um método, em uma interface ou dispinterface).|
|[iid_is](../windows/iid-is.md)|Especifica o IID da interface COM apontado por um ponteiro de interface.|
|[immediatebind](../windows/immediatebind.md)|Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto de associação de dados.|
|[importlib](../windows/importlib.md)|Torna os tipos que já foram compilados em outra biblioteca de tipos disponível para a biblioteca de tipos que está sendo criada.|
|[import](../windows/import.md)|Especifica outro arquivo. idl, odl ou cabeçalho que contém definições que você deseja fazer referência do seu arquivo. idl principal.|
|[include](../windows/include-cpp.md)|Especifica um ou mais arquivos de cabeçalho a serem incluídos no arquivo. idl gerado.|
|[includelib](../windows/includelib-cpp.md)|Faz com que um arquivo. IDL ou. h a serem incluídos no arquivo. idl gerado.|
|[in](../windows/in-cpp.md)|Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.|
|[last_is](../windows/last-is.md)|Especifica o índice do último elemento da matriz a ser transmitido.|
|[lcid](../windows/lcid.md)|Permite que você passar um identificador de localidade para uma função.|
|[length_is](../windows/length-is.md)|Especifica o número de elementos da matriz a ser transmitido.|
|[licensed](../windows/licensed.md)|Indica que a coclass ao qual se aplica é licenciada e deve ser instanciada usando `IClassFactory2`.|
|[local](../windows/local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, designa um procedimento de local para o qual nenhuma stubs são gerados.|
|[max_is](../windows/max-is.md)|Designa o valor máximo para um índice de matriz válida.|
|[módulo](../windows/module-cpp.md)|Define o bloco de biblioteca no arquivo. idl.|
|[ms_union](../windows/ms-union.md)|Controla o alinhamento de representação de dados de rede de uniões nonencapsulated.|
|[no_injected_text](../windows/no-injected-text.md)|Impede que o compilador injetando código como resultado do uso do atributo.|
|[nonbrowsable](../windows/nonbrowsable.md)|Indica que um membro de interface não deve ser exibido em um navegador de propriedade.|
|[noncreatable](../windows/noncreatable.md)|Define um objeto que não pode ser instanciado por si só.|
|[nonextensible](../windows/nonextensible.md)|Especifica que o `IDispatch` implementação inclui apenas as propriedades e os métodos listados na descrição da interface e não podem ser estendidos com membros adicionais em tempo de execução.|
|[object](../windows/object-cpp.md)|Identifica uma interface personalizada; sinônimo de atributo personalizado.|
|[odl](../windows/odl.md)|Identifica uma interface como uma interface de linguagem de descrição do objeto (ODL).|
|[oleautomation](../windows/oleautomation.md)|Indica que uma interface é compatível com a automação.|
|[Opcional](../windows/optional-cpp.md)|Especifica um parâmetro opcional para uma função de membro.|
|[out](../windows/out-cpp.md)|Identifica os parâmetros de ponteiro que são retornados do procedimento chamado ao procedimento de chamada (do servidor para o cliente).|
|[pointer_default](../windows/pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto ponteiros de nível superior que aparecem em listas de parâmetros.|
|[pragma](../windows/pragma.md)|Emite a cadeia de caracteres especificada, sem os caracteres de aspas no arquivo. idl gerado.|
|[progid](../windows/progid.md)|Especifica o ProgID de um objeto COM.|
|[propget](../windows/propget.md)|Especifica uma função de propriedade do acessador (get).|
|[propputref](../windows/propputref.md)|Especifica uma função de definição de propriedade que usa uma referência em vez de um valor.|
|[propput](../windows/propput.md)|Especifica uma função de definição de propriedade.|
|[ptr](../windows/ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[public](../windows/public-cpp-attributes.md)|Garante que um typedef entra em biblioteca de tipos, mesmo se ele não é referenciado de dentro do arquivo. idl.|
|[range](../windows/range-cpp.md)|Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.|
|[readonly](../windows/readonly-cpp.md)|Proíbe a atribuição a uma variável.|
|[ref](../windows/ref-cpp.md)|Identifica um ponteiro de referência.|
|[requestedit](../windows/requestedit.md)|Indica que a propriedade oferece suporte a `OnRequestEdit` notificação.|
|[restricted](../windows/restricted.md)|Especifica que uma biblioteca ou membro de um módulo, interface ou dispinterface não pode ser chamado arbitrariamente.|
|[retval](../windows/retval.md)|Designa o parâmetro que recebe o valor de retorno do membro.|
|[size_is](../windows/size-is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.|
|[source](../windows/source-cpp.md)|Indica que um membro de classe, propriedade ou método é uma origem de eventos.|
|[string](../windows/string-cpp.md)|Indica que o unidimensional **char**, **wchar_t**, `byte`, ou equivalente matriz ou o ponteiro para essa matriz deve ser tratado como uma cadeia de caracteres.|
|[switch_is](../windows/switch-is.md)|Especifica a expressão ou um identificador que atua como o discriminador de união que seleciona o membro de união.|
|[switch_type](../windows/switch-type.md)|Identifica o tipo da variável usada como o discriminador de união.|
|[transmit_as](../windows/transmit-as.md)|Instrui o compilador para associar um tipo apresentado, manipulam a quais aplicativos cliente e servidor, com um tipo transmitido.|
|[uidefault](../windows/uidefault.md)|Indica que o membro de informações de tipo é o membro padrão para exibição na interface do usuário.|
|[unique](../windows/unique-cpp.md)|Especifica um ponteiro exclusivo.|
|[usesgetlasterror](../windows/usesgetlasterror.md)|Informa ao chamador que se houver um erro ao chamar essa função, o chamador pode, em seguida, chamar `GetLastError` para recuperar o código de erro.|
|[uuid](../windows/uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[v1_enum](../windows/v1-enum.md)|Direciona-se de que o tipo enumerado especificado ser transmitidas como uma entidade de 32 bits, em vez do padrão de 16 bits.|
|[vararg](../windows/vararg.md)|Especifica que a função tem um número variável de argumentos.|
|[vi_progid](../windows/vi-progid.md)|Especifica uma forma independente de versão do ProgID.|
|[wire_marshal](../windows/wire-marshal.md)|Especifica um tipo de dados que será usado para transmissão em vez de um tipo de dados específicos do aplicativo.|

## <a name="see-also"></a>Consulte também

[Atributos por grupo](../windows/attributes-by-group.md)  
[Limitações de atributo](http://msdn.microsoft.com/6e6c4329-f667-4869-b991-cbe9cb7a8f61)