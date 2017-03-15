---
title: "IDL Attributes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "attributes [C++], reference topics"
  - "IDL attributes"
  - ".idl files, attributes"
  - "IDL files, attributes"
  - ".idl files"
ms.assetid: 04c596f4-c97b-4952-8053-316678b1d0b6
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IDL Attributes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Tradicionalmente, a manutenção de um arquivo. idl significava que era necessário:  
  
-   Estar familiarizado com a estrutura e sintaxe de um arquivo. idl para poder modificá\-lo.  
  
-   Contar com um assistente que permitiria modificar certos aspectos do arquivo. idl.  
  
 Agora, você pode modificar o arquivo. idl a partir de um arquivo de código\-fonte usando atributos IDL do Visual C\+\+.  Em muitos casos, os atributos IDL do Visual C\+\+ têm o mesmo nome como atributos MIDL.  Quando o nome de um atributo de IDL do Visual C\+\+ e um atributo MIDL forem iguais, isso significa que a colocar o atributo do Visual C\+\+ em seu arquivo de código\-fonte resultará em um arquivo. idl que contém seu atributo MIDL por homônimo.  No entanto, um atributo de IDL do Visual C\+\+ pode não fornecer toda a funcionalidade de um atributo MIDL.  
  
 Quando não é usado com  [atributos COM](../Topic/COM%20Attributes.md), atributos IDL permitem definir interfaces.  Quando o código\-fonte é compilado, os atributos são usados para definir o arquivo. idl gerado.  Quando usado com atributos de COM em um projeto do ATL, alguns IDL atributos, como  **coclass**, fazer com que o código seja injetado no projeto.  
  
 Observe que  [idl\_quote](../windows/idl-quote.md) permite o uso de construções MIDL que não são suportadas na versão atual do Visual C\+\+.  Esse e outros atributos, como  [importlib](../windows/importlib.md) e  [includelib](../windows/includelib-cpp.md) ajudam você a usar os arquivos. idl existentes em seu projeto atual do Visual C\+\+.  
  
|Atributo|Descrição|  
|--------------|---------------|  
|[agregável](../Topic/aggregatable.md)|Indica que um controle pode ser agregado por outro controle.|  
|[appobject](../Topic/appobject.md)|Identifica o coclass como um objeto de aplicativo, que está associado um aplicativo completo do EXE e indica que as funções e propriedades do coclass estão disponíveis globalmente nesta biblioteca de tipo.|  
|[async\_uuid](../Topic/async_uuid.md)|Especifica o UUID que instrui o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.|  
|[ligáveis](../windows/bindable.md)|Indica que a propriedade oferece suporte a vinculação de dados.|  
|[call\_as](../windows/call-as.md)|Permite que uma função não remota seja mapeada para uma função remota.|  
|[Caso](../windows/case-cpp.md)|Usado com o  [switch\_type](../windows/switch-type.md) atributo em uma união.|  
|[coclass](../windows/coclass.md)|Locais de definição em um arquivo. idl como coclass de classe.|  
|[controle](../windows/control.md)|Especifica que o tipo definido pelo usuário é um controle.|  
|[cpp\_quote](../Topic/cpp_quote.md)|Emite a seqüência de caracteres especificada sem os caracteres de cotação, no arquivo de cabeçalho gerado.|  
|[defaultbind](../windows/defaultbind.md)|Indica a propriedade única e vinculável que melhor representa o objeto.|  
|[defaultcollelem](../windows/defaultcollelem.md)|Usado para otimização de código Visual Basic.|  
|[Valor padrão](../Topic/defaultvalue.md)|Permite a especificação de um valor padrão para um parâmetro opcional digitado.|  
|[Padrão](../windows/default-cpp.md)|Indica que o personalizado ou um dispinterface definido dentro de um coclass representa a interface de programação padrão.|  
|[defaultvtable](../windows/defaultvtable.md)|Define uma interface como interface padrão vtable para um controle.|  
|[dispinterface](../windows/dispinterface.md)|Coloca uma interface no arquivo. idl como uma interface de despacho.|  
|[displaybind](../windows/displaybind.md)|Indica uma propriedade que deve ser exibida ao usuário como bindable.|  
|[dual](../Topic/dual.md)|Coloca uma interface no arquivo. idl como uma interface dupla.|  
|[entrada](../windows/entry.md)|Especifica uma função exportada ou constante em um módulo, identificando o ponto de entrada na DLL.|  
|[first\_is](../windows/first-is.md)|Especifica o índice do primeiro elemento da matriz para serem transmitidos.|  
|[HelpContext](../windows/helpcontext.md)|Especifica uma identificação de contexto que permite que as informações de modo de exibição do usuário sobre este elemento no arquivo de Ajuda.|  
|[arquivo de ajuda](../Topic/helpfile.md)|Define o nome do arquivo de ajuda para uma biblioteca de tipos.|  
|[helpstringcontext](../windows/helpstringcontext.md)|Especifica a ID de um tópico da ajuda em um arquivo .hlp ou .chm.|  
|[helpstringdll](../windows/helpstringdll.md)|Especifica o nome da DLL a ser usada para executar a pesquisa de  string no documento \(localização\).|  
|[HelpString](../windows/helpstring.md)|Especifica a string que é usada para descrever o elemento a que se aplica.|  
|[oculto](../Topic/hidden.md)|Indica que o item existe mas não deve ser exibido em um navegador orientado a usuário.|  
|[idl\_module](../windows/idl-module.md)|Especifica um ponto de entrada em uma DLL.|  
|[idl\_quote](../windows/idl-quote.md)|Permite que você use os atributos ou IDL construções que não são suportados na versão atual do Visual C\+\+.|  
|[id](../windows/id.md)|Especifica um DISPID para uma função membro \(uma propriedade ou um método, em uma interface ou dispinterface\).|  
|[iid\_is](../windows/iid-is.md)|Especifica o IID da interface COM apontada por um ponteiro de interface.|  
|[immediatebind](../windows/immediatebind.md)|Indica que o banco de dados será notificado imediatamente de todas as alterações a uma propriedade de um objeto de dados vinculado.|  
|[importlib](../windows/importlib.md)|Faz com que tipos de já tem sido compilados em outra biblioteca de tipos disponível para a biblioteca de tipos que está sendo criada.|  
|[Importar](../windows/import.md)|Especifica outro arquivo. idl, odl ou cabeçalho que contém definições que você deseja referenciar no seu arquivo. idl principal.|  
|[incluir](../windows/include-cpp.md)|Especifica um ou mais arquivos de cabeçalho a serem incluídos no arquivo. idl gerado.|  
|[includelib](../windows/includelib-cpp.md)|Faz com que um arquivo. idl ou. h para ser incluído no arquivo. idl gerado.|  
|[Em](../Topic/in%20\(C++\).md)|Indica que é um parâmetro a ser passado do procedimento de chamada para o procedimento chamado.|  
|[last\_is](../windows/last-is.md)|Especifica o índice do último elemento de matriz para serem transmitidos.|  
|[LCID](../windows/lcid.md)|Permite que você passa um identificador de localidade para uma função.|  
|[length\_is](../windows/length-is.md)|Especifica o número de elementos da matriz para serem transmitidos.|  
|[Licenciado](../windows/licensed.md)|Indica que o coclass ao qual ele se aplica é licenciado e deve ser instanciada usando  **IClassFactory2**.|  
|[local](../windows/local-cpp.md)|Permite que você use o compilador MIDL como um gerador de cabeçalho quando usado no cabeçalho da interface.  Quando usado em uma função individual, designa um procedimento de local para o qual nenhum fragmento de código é gerados.|  
|[max\_is](../windows/max-is.md)|Designa o valor máximo para um índice de matriz válido.|  
|[módulo](../windows/module-cpp.md)|Define o bloco de biblioteca no arquivo. idl.|  
|[ms\_union](../windows/ms-union.md)|Controla o alinhamento de representação de dados de rede de uniões nonencapsulated.|  
|[no\_injected\_text](../windows/no-injected-text.md)|Impede que o compilador de injeção de código como resultado do uso do atributo.|  
|[nonbrowsable](../Topic/nonbrowsable.md)|Indica que um membro da interface não deve ser exibido em um navegador de propriedade.|  
|[noncreatable](../windows/noncreatable.md)|Define um objeto que não pode ser instanciado por si só.|  
|[não](../Topic/nonextensible.md)|Especifica que o `IDispatch` a implementação inclui somente as propriedades e métodos listados na descrição da interface e não podem ser estendidos com membros adicionais em tempo de execução.|  
|[object](../Topic/object%20\(C++\).md)|Identifica uma interface personalizada; sinônimo de atributo personalizado.|  
|[odl](../windows/odl.md)|Identifica uma interface como uma interface de linguagem de descrição de objeto \(ODL\).|  
|[oleautomation](../windows/oleautomation.md)|Indica que uma interface é compatível com a automação.|  
|[opcional](../windows/optional-cpp.md)|Especifica um parâmetro opcional para uma função de membro.|  
|[Limite](../Topic/out%20\(C++\).md)|Identifica os parâmetros de ponteiro que são retornados pelo procedimento chamado ao procedimento de chamada \(a partir do servidor para o cliente\).|  
|[pointer\_default](../windows/pointer-default.md)|Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto os ponteiros de nível superior que aparecem em listas de parâmetros.|  
|[pragma](../windows/pragma.md)|Emite a seqüência de caracteres especificada sem os caracteres de cotação, no arquivo. idl gerado.|  
|[ProgID](../Topic/progid.md)|Especifica o ProgID de um objeto COM.|  
|[propget](../windows/propget.md)|Especifica uma função de assessor \(get\) de propriedade.|  
|[propputref](../windows/propputref.md)|Especifica uma função de configuração de propriedade que usa uma referência em vez de um valor.|  
|[propput](../windows/propput.md)|Especifica uma função de configuração da propriedade.|  
|[PTR](../windows/ptr.md)|Designa um ponteiro como um ponteiro completo.|  
|[Público](../windows/public-cpp-attributes.md)|Garante que um typedef irá para a biblioteca de tipo, mesmo que não é referenciado no dentro do arquivo. idl.|  
|[intervalo](../Topic/range%20\(C++\).md)|Especifica um intervalo de valores permitidos para os argumentos ou campos cujos valores são definidos em tempo de execução.|  
|[readonly](../windows/readonly-cpp.md)|Proíbe a atribuição a uma variável.|  
|[Ref](../windows/ref-cpp.md)|Identifica um ponteiro de referência.|  
|[requestedit](../windows/requestedit.md)|Indica que a propriedade oferece suporte a  **OnRequestEdit** notificação.|  
|[restrito](../windows/restricted.md)|Especifica que uma biblioteca ou um membro de um módulo, interface ou dispinterface não pode ser chamado arbitrariamente.|  
|[retval](../windows/retval.md)|Designa o parâmetro que recebe o valor de retorno do membro.|  
|[size\_is](../Topic/size_is.md)|Especifica o tamanho da memória alocada para ponteiros de tamanho, em tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.|  
|[fonte](../Topic/source%20\(C++\).md)|Indica que o membro de uma classe, propriedade ou método é uma fonte de eventos.|  
|[string](../windows/string-cpp.md)|Indica que o unidimensional `char`, `wchar_t`,  **bytes**, ou array equivalente ou o ponteiro para essa matriz deve ser tratado como uma seqüência de caracteres.|  
|[switch\_is](../windows/switch-is.md)|Especifica a expressão ou um identificador que atua como o discriminant de união que seleciona o membro da união.|  
|[switch\_type](../windows/switch-type.md)|Identifica o tipo da variável usado como o discriminant de união.|  
|[transmit\_as](../windows/transmit-as.md)|Instrui o compilador para associar um tipo apresentado, manipulam a quais aplicativos cliente e servidor, um tipo transmitido.|  
|[uidefault](../Topic/uidefault.md)|Indica que o membro de informações de tipo é o membro padrão para exibição na interface do usuário.|  
|[exclusivo](../windows/unique-cpp.md)|Especifica um indicador único.|  
|[usesgetlasterror](../windows/usesgetlasterror.md)|Informa ao chamador que se houver um erro ao chamar essa função, o chamador pode, em seguida, chamar `GetLastError` para recuperar o código de erro.|  
|[UUID](../windows/uuid-cpp-attributes.md)|Especifica a identificação exclusiva de uma classe ou interface.|  
|[v1\_enum](../windows/v1-enum.md)|Dirige\-se de que o tipo enumerado especificado ser transmitidas como uma entidade de 32 bits, em vez do padrão de 16 bits.|  
|[vararg](../windows/vararg.md)|Especifica que a função levar um número variável de argumentos.|  
|[vi\_progid](../windows/vi-progid.md)|Especifica um formulário independente de versão de ProgID.|  
|[wire\_marshal](../windows/wire-marshal.md)|Especifica um tipo de dados que será usado para transmissão em vez de um tipo de dados específicos do aplicativo.|  
  
## Consulte também  
 [Attributes by Group](../windows/attributes-by-group.md)   
 [Attribute Limitations](http://msdn.microsoft.com/pt-br/6e6c4329-f667-4869-b991-cbe9cb7a8f61)