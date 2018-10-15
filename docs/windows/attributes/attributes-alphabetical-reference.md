---
title: Referência alfabética de atributos | Microsoft Docs
ms.custom: index-page
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.attributes
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++/CLI]
ms.assetid: fb2216ef-9fbd-44f4-afed-732aa99450e2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 431ca9e88e644bd7a7c38f9ab4a1c3faeab6f9bb
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49328396"
---
# <a name="attributes-alphabetical-reference"></a>Referência alfabética de atributos

Os seguintes atributos estão disponíveis no compilador C++ da Microsoft:

|Atributo|Descrição|
|---------------|-----------------|
|[aggregatable](aggregatable.md)|Indica se um controle pode ser agregado por outro controle.|
|[aggregates](aggregates.md)|Indica que um controle agrega a classe de destino.|
|[appobject](appobject.md)|Identifica a coclass como um objeto de aplicativo, que é associado um aplicativo completo do EXE e indica que as funções e propriedades da coclass estão globalmente disponíveis na biblioteca de tipo.|
|[async_uuid](async-uuid.md)|Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.|
|[attribute](attribute.md)|Permite que você crie um atributo personalizado.|
|[bindable](bindable.md)|Indica que a propriedade dá suporte à associação de dados.|
|[call_as](call-as.md)|Permite que uma função nonremotable a ser mapeada para uma função remota.|
|[case](case-cpp.md)|Usado com o [switch_type](switch-type.md) atributo em uma união.|
|[coclass](coclass.md)|Cria um objeto COM, que pode implementar uma interface COM.|
|[com_interface_entry](com-interface-entry-cpp.md)|Adiciona uma entrada de interface para um mapa COM.|
|[control](control.md)|Especifica que o tipo definido pelo usuário é um controle.|
|[cpp_quote](cpp-quote.md)|Emite a cadeia de caracteres especificada, sem caracteres de aspas, para o arquivo de cabeçalho gerado.|
|[custom](custom-cpp.md)|Permite definir seus próprios atributos.|
|[db_accessor](db-accessor.md)|Associa as colunas em um conjunto de linhas e associa-os para os mapas de acessador correspondente.|
|[db_column](db-column.md)|Associa uma coluna especificada para o conjunto de linhas.|
|[db_command](db-command.md)|Executa um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído.|
|[db_source](db-source.md)|Cria e encapsula uma conexão, por meio de um provedor, a fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela de OLE DB.|
|[default](default-cpp.md)|Indica que o personalizado ou dispinterface definido dentro de uma coclass representa a interface de programação padrão.|
|[defaultbind](defaultbind.md)|Indica a única propriedade associável que melhor representa o objeto.|
|[defaultcollelem](defaultcollelem.md)|Usada para otimização de código do Visual Basic.|
|[defaultvalue](defaultvalue.md)|Permite a especificação de um valor padrão para um parâmetro opcional tipado.|
|[defaultvtable](defaultvtable.md)|Define uma interface como a interface de vtable padrão para um controle.|
|[dispinterface](dispinterface.md)|Coloca uma interface no arquivo. idl como uma interface de expedição.|
|[displaybind](displaybind.md)|Indica uma propriedade que deve ser exibida para o usuário como associável.|
|[dual](dual.md)|Coloca uma interface no arquivo. idl como uma interface dupla.|
|[emitidl](emitidl.md)|Determina se todos os atributos IDL subsequentes serão processados e colocados no arquivo. idl gerado.|
|[entry](entry.md)|Especifica uma constante ou uma função exportada em um módulo, identificando o ponto de entrada na DLL.|
|[event_receiver](event-receiver.md)|Cria um receptor de eventos.|
|[event_source](event-source.md)|Cria uma origem de evento.|
|[export](export.md)|Faz com que uma estrutura de dados a serem colocados no arquivo. idl.|
|[first_is](first-is.md)|Especifica o índice do primeiro elemento da matriz a ser transmitido.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite que usuários exibir informações sobre esse elemento no arquivo de Ajuda.|
|[helpfile](helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstring](helpstring.md)|Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.|
|[helpstringdll](helpstringdll.md)|Especifica o nome da DLL a usar para executar a pesquisa de cadeia de caracteres do documento (localização).|
|[hidden](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[id](id.md)|Especifica um DISPID para uma função de membro (uma propriedade ou um método, em uma interface ou dispinterface).|
|[idl_module](idl-module.md)|Especifica um ponto de entrada em uma DLL.|
|[idl_quote](idl-quote.md)|Permite que você use atributos ou IDL construções que não são suportados na versão atual do Visual C++.|
|[iid_is](iid-is.md)|Especifica o IID da interface COM apontado por um ponteiro de interface.|
|[immediatebind](immediatebind.md)|Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto de associação de dados.|
|[implements](implements-cpp.md)|Especifica as interfaces de distribuição que são forçadas para serem membros da coclass IDL.|
|[implements_category](implements-category.md)|Especifica as categorias de componentes implementados para a classe.|
|[import](import.md)|Especifica outro arquivo. idl, odl ou cabeçalho que contém definições que você deseja fazer referência do seu arquivo. idl principal.|
|[importidl](importidl.md)|Insere o arquivo. idl especificado no arquivo. idl gerado.|
|[importlib](importlib.md)|Torna os tipos que já foram compilados em outra biblioteca de tipos disponível para a biblioteca de tipos que está sendo criada.|
|[in](in-cpp.md)|Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.|
|[include](include-cpp.md)|Especifica um ou mais arquivos de cabeçalho a serem incluídos no arquivo. idl gerado.|
|[includelib](includelib-cpp.md)|Faz com que um arquivo. IDL ou. h a serem incluídos no arquivo. idl gerado.|
|[last_is](last-is.md)|Especifica o índice do último elemento da matriz a ser transmitido.|
|[lcid](lcid.md)|Permite que você passar um identificador de localidade para uma função.|
|[length_is](length-is.md)|Especifica o número de elementos da matriz a ser transmitido.|
|[library_block](library-block.md)|Coloca uma construção de dentro do bloco de biblioteca do arquivo. idl.|
|[licensed](licensed.md)|Indica que a coclass ao qual se aplica é licenciada e deve ser instanciada usando `IClassFactory2`.|
|[local](local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, designa um procedimento de local para o qual nenhuma stubs são gerados.|
|[max_is](max-is.md)|Designa o valor máximo para um índice de matriz válida.|
|[module](module-cpp.md)|Define o bloco de biblioteca no arquivo. idl.|
|[ms_union](ms-union.md)|Controla o alinhamento de representação de dados de rede de uniões nonencapsulated.|
|[no_injected_text](no-injected-text.md)|Impede que o compilador injetando código como resultado do uso do atributo.|
|[nonbrowsable](nonbrowsable.md)|Indica que um membro de interface não deve ser exibido em um navegador de propriedade.|
|[noncreatable](noncreatable.md)|Define um objeto que não pode ser instanciado por si só.|
|[nonextensible](nonextensible.md)|Especifica que o `IDispatch` implementação inclui apenas as propriedades e os métodos listados na descrição da interface e não podem ser estendidos com membros adicionais em tempo de execução.|
|[object](object-cpp.md)|Identifica uma interface personalizada; sinônimo de atributo personalizado.|
|[odl](odl.md)|Identifica uma interface como uma interface de linguagem de descrição do objeto (ODL).|
|[oleautomation](oleautomation.md)|Indica que uma interface é compatível com a automação.|
|[optional](optional-cpp.md)|Especifica um parâmetro opcional para uma função de membro.|
|[out](out-cpp.md)|Identifica os parâmetros de ponteiro que são retornados do procedimento chamado ao procedimento de chamada (do servidor para o cliente).|
|[pointer_default](pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto ponteiros de nível superior que aparecem em listas de parâmetros.|
|[pragma](pragma.md)|Emite a cadeia de caracteres especificada, sem os caracteres de aspas no arquivo. idl gerado.|
|[progid](progid.md)|Especifica o ProgID de um objeto COM.|
|[propget](propget.md)|Especifica uma função de propriedade do acessador (get).|
|[propput](propput.md)|Especifica uma função de definição de propriedade.|
|[propputref](propputref.md)|Especifica uma função de definição de propriedade que usa uma referência em vez de um valor.|
|[ptr](ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[public](public-cpp-attributes.md)|Garante que um typedef entra em biblioteca de tipos, mesmo se ele não é referenciado de dentro do arquivo. idl.|
|[range](range-cpp.md)|Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.|
|[rdx](rdx.md)|Cria ou modifica uma chave do registro.|
|[readonly](readonly-cpp.md)|Proíbe a atribuição a uma variável.|
|[ref](ref-cpp.md)|Identifica um ponteiro de referência.|
|[registration_script](registration-script.md)|Executa o script de registro especificado.|
|[requestedit](requestedit.md)|Indica que a propriedade oferece suporte a `OnRequestEdit` notificação.|
|[requires_category](requires-category.md)|Especifica as categorias de componente necessário para a classe.|
|[restricted](restricted.md)|Especifica que uma biblioteca ou membro de um módulo, interface ou dispinterface não pode ser chamado arbitrariamente.|
|[retval](retval.md)|Designa o parâmetro que recebe o valor de retorno do membro.|
|[satype](satype.md)|Especifica o tipo de dados a `SAFEARRAY`.|
|[size_is](size-is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.|
|[source](source-cpp.md)|Indica que um membro de classe, propriedade ou método é uma origem de eventos.|
|[string](string-cpp.md)|Indica que o unidimensional **char**, **wchar_t**, `byte`, ou equivalente matriz ou o ponteiro para essa matriz deve ser tratado como uma cadeia de caracteres.|
|[support_error_info](support-error-info.md)|Dá suporte a relatórios de erros para o objeto de destino.|
|[switch_is](switch-is.md)|Especifica a expressão ou um identificador que atua como o discriminador de união que seleciona o membro de união.|
|[switch_type](switch-type.md)|Identifica o tipo da variável usada como o discriminador de união.|
|[synchronize](synchronize.md)|Sincroniza o acesso a um método.|
|[threading](threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|
|[transmit_as](transmit-as.md)|Instrui o compilador para associar um tipo apresentado, manipulam a quais aplicativos cliente e servidor, com um tipo transmitido.|
|[uidefault](uidefault.md)|Indica que o membro de informações de tipo é o membro padrão para exibição na interface do usuário.|
|[unique](unique-cpp.md)|Especifica um ponteiro exclusivo.|
|[usesgetlasterror](usesgetlasterror.md)|Informa ao chamador que se houver um erro ao chamar essa função, o chamador pode, em seguida, chamar `GetLastError` para recuperar o código de erro.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[v1_enum](v1-enum.md)|Direciona-se de que o tipo enumerado especificado ser transmitidas como uma entidade de 32 bits, em vez do padrão de 16 bits.|
|[vararg](vararg.md)|Especifica que a função tem um número variável de argumentos.|
|[version](version-cpp.md)|Identifica uma versão específica entre várias versões de uma interface ou classe.|
|[vi_progid](vi-progid.md)|Especifica uma forma independente de versão do ProgID.|
|[wire_marshal](wire-marshal.md)|Especifica um tipo de dados que será usado para transmissão em vez de um tipo de dados específicos do aplicativo.|

## <a name="see-also"></a>Consulte também

[Atributos C++ para COM e .NET](cpp-attributes-com-net.md)<br/>
[Atributos por grupo](attributes-by-group.md)<br/>
[Atributos por uso](attributes-by-usage.md)