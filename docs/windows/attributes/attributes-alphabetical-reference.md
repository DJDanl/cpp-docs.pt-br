---
title: Referência alfabética de atributos
ms.custom: index-page
ms.date: 10/02/2018
ms.topic: conceptual
f1_keywords:
- vc.attributes
helpviewer_keywords:
- attributes [C++/CLI]
ms.assetid: fb2216ef-9fbd-44f4-afed-732aa99450e2
ms.openlocfilehash: ad9ecd1e3b3d4620b1f862fd1d5d70ef050da48d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215329"
---
# <a name="attributes-alphabetical-reference"></a>Referência alfabética de atributos

Os seguintes atributos estão disponíveis no compilador do Microsoft C++:

|Atributo|Descrição|
|---------------|-----------------|
|[aggregatable](aggregatable.md)|Indica que um controle pode ser agregado por outro controle.|
|[agregações](aggregates.md)|Indica que um controle agrega a classe de destino.|
|[appobject](appobject.md)|Identifica a coclass como um objeto Application, que está associado a um aplicativo EXE completo e indica que as funções e as propriedades da coclass estão disponíveis globalmente nesta biblioteca de tipos.|
|[async_uuid](async-uuid.md)|Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.|
|[Attribute](attribute.md)|Permite que você crie um atributo personalizado.|
|[bindable](bindable.md)|Indica que a propriedade dá suporte à associação de dados.|
|[call_as](call-as.md)|Permite que uma função não Remotable seja mapeada para uma função remota.|
|[casos](case-cpp.md)|Usado com o atributo [switch_type](switch-type.md) em uma Union.|
|[coclass](coclass.md)|Cria um objeto COM, que pode implementar uma interface COM.|
|[com_interface_entry](com-interface-entry-cpp.md)|Adiciona uma entrada de interface a um mapa COM.|
|[control](control.md)|Especifica que o tipo definido pelo usuário é um controle.|
|[cpp_quote](cpp-quote.md)|Emite a cadeia de caracteres especificada, sem os caracteres de aspas, no arquivo de cabeçalho gerado.|
|[Personalizar](custom-cpp.md)|Permite que você defina seus próprios atributos.|
|[db_accessor](db-accessor.md)|Associa colunas em um conjunto de linhas e as associa aos mapas de acessadores correspondentes.|
|[db_column](db-column.md)|Associa uma coluna especificada ao conjunto de linhas.|
|[db_command](db-command.md)|Executa um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificada a um parâmetro de entrada ou saída.|
|[db_source](db-source.md)|Cria e encapsula uma conexão, por meio de um provedor, para uma fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela OLE DB.|
|[os](default-cpp.md)|Indica que a dispinterface ou personalizada definida em uma coclass representa a interface de programação padrão.|
|[defaultbind](defaultbind.md)|Indica a propriedade única e vinculável que melhor representa o objeto.|
|[defaultcollelem](defaultcollelem.md)|Usado para Visual Basic otimização de código.|
|[ValorPadrão](defaultvalue.md)|Permite a especificação de um valor padrão para um parâmetro opcional tipado.|
|[defaultvtable](defaultvtable.md)|Define uma interface como a interface vtable padrão para um controle.|
|[dispinterface](dispinterface.md)|Coloca uma interface no arquivo. idl como uma interface de expedição.|
|[displaybind](displaybind.md)|Indica uma propriedade que deve ser exibida para o usuário como vinculável.|
|[dual](dual.md)|Coloca uma interface no arquivo. idl como uma interface dupla.|
|[emitidl](emitidl.md)|Determina se todos os atributos IDL subsequentes serão processados e colocados no arquivo. idl gerado.|
|[inicial](entry.md)|Especifica uma função ou constante exportada em um módulo identificando o ponto de entrada na DLL.|
|[event_receiver](event-receiver.md)|Cria um receptor de eventos.|
|[event_source](event-source.md)|Cria uma origem de evento.|
|[Export](export.md)|Faz com que uma estrutura de dados seja colocada no arquivo. idl.|
|[first_is](first-is.md)|Especifica o índice do primeiro elemento de matriz a ser transmitido.|
|[helpcontext](helpcontext.md)|Especifica uma ID de contexto que permite ao usuário exibir informações sobre esse elemento no arquivo de ajuda.|
|[helpfile](helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|
|[helpstring](helpstring.md)|Especifica a ID de um tópico da ajuda em um arquivo. hlp ou. chm.|
|[helpstringdll](helpstringdll.md)|Especifica o nome da DLL a ser usada para executar a pesquisa de cadeia de caracteres do documento (localização).|
|[oculto](hidden.md)|Indica que o item existe, mas não deve ser exibido em um navegador orientado ao usuário.|
|[id](id.md)|Especifica um DISPID para uma função membro (uma propriedade ou um método, em uma interface ou Dispinterface).|
|[idl_module](idl-module.md)|Especifica um ponto de entrada em uma DLL.|
|[idl_quote](idl-quote.md)|Permite que você use atributos ou construções de IDL que não têm suporte na versão atual do Visual C++.|
|[iid_is](iid-is.md)|Especifica o IID da interface COM apontada por um ponteiro de interface.|
|[immediatebind](immediatebind.md)|Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto associado a um dado.|
|[implementa](implements-cpp.md)|Especifica as interfaces de expedição que são forçadas a serem membros da coclasse IDL.|
|[implements_category](implements-category.md)|Especifica as categorias de componente implementadas para a classe.|
|[import](import.md)|Especifica outro arquivo. idl,. odl ou de cabeçalho que contém as definições que você deseja referenciar do seu arquivo. idl principal.|
|[importidl](importidl.md)|Insere o arquivo. idl especificado no arquivo. idl gerado.|
|[importlib](importlib.md)|Torna os tipos que já foram compilados em outra biblioteca de tipos disponíveis para a biblioteca de tipos que está sendo criada.|
|[no](in-cpp.md)|Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.|
|[incluir](include-cpp.md)|Especifica um ou mais arquivos de cabeçalho a serem incluídos no arquivo. idl gerado.|
|[includelib](includelib-cpp.md)|Faz com que um arquivo. IDL ou. h seja incluído no arquivo. idl gerado.|
|[last_is](last-is.md)|Especifica o índice do último elemento de matriz a ser transmitido.|
|[lcid](lcid.md)|Permite passar um identificador de localidade para uma função.|
|[length_is](length-is.md)|Especifica o número de elementos da matriz a serem transmitidos.|
|[library_block](library-block.md)|Coloca uma construção dentro do bloco de biblioteca do arquivo. idl.|
|[licensed](licensed.md)|Indica que a coclass à qual ela se aplica é licenciada e deve ser instanciada usando `IClassFactory2` .|
|[local](local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface. Quando usado em uma função individual, o designa um procedimento local para o qual nenhum stub é gerado.|
|[max_is](max-is.md)|Designa o valor máximo para um índice de matriz válido.|
|[modulo](module-cpp.md)|Define o bloco de biblioteca no arquivo. idl.|
|[ms_union](ms-union.md)|Controla o alinhamento da representação de dados de rede de uniões não encapsuladas.|
|[no_injected_text](no-injected-text.md)|Impede que o compilador insira código como resultado do uso do atributo.|
|[nonbrowsable](nonbrowsable.md)|Indica que um membro de interface não deve ser exibido em um navegador de propriedades.|
|[noncreatable](noncreatable.md)|Define um objeto que não pode ser instanciado por si só.|
|[nonextensible](nonextensible.md)|Especifica que a `IDispatch` implementação inclui apenas as propriedades e os métodos listados na descrição da interface e não pode ser estendido com membros adicionais em tempo de execução.|
|[object](object-cpp.md)|Identifica uma interface personalizada; sinônimo de atributo personalizado.|
|[odl](odl.md)|Identifica uma interface como uma interface de linguagem de descrição de objeto (ODL).|
|[oleautomation](oleautomation.md)|Indica que uma interface é compatível com a automação.|
|[adicional](optional-cpp.md)|Especifica um parâmetro opcional para uma função de membro.|
|[fora](out-cpp.md)|Identifica os parâmetros de ponteiro que são retornados do procedimento chamado para o procedimento de chamada (do servidor para o cliente).|
|[pointer_default](pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto para os ponteiros de nível superior que aparecem nas listas de parâmetros.|
|[pragma](pragma.md)|Emite a cadeia de caracteres especificada, sem os caracteres de aspas, no arquivo. idl gerado.|
|[ProgID](progid.md)|Especifica o ProgID de um objeto COM.|
|[propget](propget.md)|Especifica uma função de acessador de propriedade (Get).|
|[propput](propput.md)|Especifica uma função de configuração de propriedade.|
|[propputref](propputref.md)|Especifica uma função de configuração de propriedade que usa uma referência em vez de um valor.|
|[ptr](ptr.md)|Designa um ponteiro como um ponteiro completo.|
|[público](public-cpp-attributes.md)|Garante que um typedef entrará na biblioteca de tipos, mesmo que não seja referenciado de dentro do arquivo. idl.|
|[range](range-cpp.md)|Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.|
|[rdx](rdx.md)|Cria ou modifica uma chave do registro.|
|[leitura](readonly-cpp.md)|Proíbe a atribuição a uma variável.|
|[ref](ref-cpp.md)|Identifica um ponteiro de referência.|
|[registration_script](registration-script.md)|Executa o script de registro especificado.|
|[requestedit](requestedit.md)|Indica que a propriedade dá suporte à notificação `OnRequestEdit`.|
|[requires_category](requires-category.md)|Especifica as categorias de componente necessárias para a classe.|
|[Restricted](restricted.md)|Especifica que uma biblioteca ou membro de um módulo, interface ou Dispinterface não pode ser chamado arbitrariamente.|
|[retval](retval.md)|Designa o parâmetro que recebe o valor de retorno do membro.|
|[satype](satype.md)|Especifica o tipo de dados do `SAFEARRAY` .|
|[size_is](size-is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, ponteiros de tamanho para ponteiros de tamanho e matrizes de dimensão única ou multidimensional.|
|[source](source-cpp.md)|Indica que um membro de uma classe, propriedade ou método é uma fonte de eventos.|
|[cadeia de caracteres](string-cpp.md)|Indica que a matriz unidimensional **`char`** , **`wchar_t`** , `byte` ou equivalente ou o ponteiro para tal matriz deve ser tratado como uma cadeia de caracteres.|
|[support_error_info](support-error-info.md)|Dá suporte ao relatório de erros para o objeto de destino.|
|[switch_is](switch-is.md)|Especifica a expressão ou o identificador que atua como o discriminante de União que seleciona o membro da União.|
|[switch_type](switch-type.md)|Identifica o tipo da variável usada como discriminante de União.|
|[novamente](synchronize.md)|Sincroniza o acesso a um método.|
|[Threading](threading-cpp.md)|Especifica o modelo de threading para um objeto COM.|
|[transmit_as](transmit-as.md)|Instrui o compilador a associar um tipo apresentado, quais aplicativos de cliente e servidor manipulam, com um tipo transmitido.|
|[uidefault](uidefault.md)|Indica que o membro de informações de tipo é o membro padrão para exibição na interface do usuário.|
|[unique](unique-cpp.md)|Especifica um ponteiro exclusivo.|
|[usesgetlasterror](usesgetlasterror.md)|Informa ao chamador que, se houver um erro ao chamar essa função, o chamador poderá então chamar `GetLastError` para recuperar o código de erro.|
|[uuid](uuid-cpp-attributes.md)|Especifica a ID exclusiva para uma classe ou interface.|
|[v1_enum](v1-enum.md)|Direciona que o tipo enumerado especificado seja transmitido como uma entidade de 32 bits, em vez do padrão de 16 bits.|
|[vararg](vararg.md)|Especifica que a função assume um número variável de argumentos.|
|[version](version-cpp.md)|Identifica uma versão específica entre várias versões de uma interface ou classe.|
|[vi_progid](vi-progid.md)|Especifica uma forma independente de versão do ProgID.|
|[wire_marshal](wire-marshal.md)|Especifica um tipo de dados que será usado para transmissão em vez de um tipo de dados específico do aplicativo.|

## <a name="see-also"></a>Confira também

[Atributos C++ para COM e .NET](cpp-attributes-com-net.md)<br/>
[Atributos por grupo](attributes-by-group.md)<br/>
[Atributos por uso](attributes-by-usage.md)
