---
title: Serviços do modelo de objeto de tempo de execução
ms.date: 03/27/2019
helpviewer_keywords:
- run-time object model services macros
ms.assetid: 4a3e79df-2ee3-43a4-8193-20298828de85
ms.openlocfilehash: f1cefdad368ebcd006dcb4ecf653247147f36d03
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372936"
---
# <a name="run-time-object-model-services"></a>Serviços do modelo de objeto de tempo de execução

As classes [CObject](../../mfc/reference/cobject-class.md) e [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) encapsulam vários serviços de objeto, incluindo acesso a informações de classe de tempo de execução, serialização e criação de objetos dinâmicos. Todas as classes `CObject` derivadas herdam essa funcionalidade.

O acesso às informações da classe de tempo de execução permite determinar informações sobre a classe de um objeto em tempo de execução. A capacidade de determinar a classe de um objeto em tempo de execução é útil quando você precisa de uma verificação de tipo extra dos argumentos de função e quando você deve escrever código de propósito especial com base na classe de um objeto. As informações da classe de tempo de execução não são suportadas diretamente pelo idioma C++.

Serialização é o processo de escrever ou ler o conteúdo de um objeto para ou a partir de um arquivo. Você pode usar serialização para armazenar o conteúdo de um objeto mesmo após a saída do aplicativo. O objeto pode então ser lido a partir do arquivo quando o aplicativo é reiniciado. Esses objetos de dados são considerados "persistentes".

A criação dinâmica de objetos permite criar um objeto de uma classe especificada em tempo de execução. Por exemplo, objetos de documento, visualização e quadro devem suportar a criação dinâmica porque a estrutura precisa criá-los dinamicamente.

A tabela a seguir lista as macros MFC que suportam informações de classe de tempo de execução, serialização e criação dinâmica.

Para obter mais informações sobre esses serviços de objeto sumido e serialização, consulte o artigo [CObject Class: Acessando informações de classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).

### <a name="run-time-object-model-services-macros"></a>Macros do modelo de objeto em tempo de execução

|||
|-|-|
|[DECLARE_DYNAMIC](#declare_dynamic)|Permite o acesso às informações da classe de tempo de execução (deve ser usado na declaração de classe).|
|[DECLARE_DYNCREATE](#declare_dyncreate)|Permite a criação dinâmica e o acesso a informações de classe em tempo de execução (devem ser usados na declaração de classe).|
|[DECLARE_SERIAL](#declare_serial)|Permite serialização e acesso a informações de classe em tempo de execução (devem ser usadas na declaração de classe).|
|[IMPLEMENT_DYNAMIC](#implement_dynamic)|Permite o acesso a informações de classe em tempo de execução (deve ser usado na implementação da classe).|
|[IMPLEMENT_DYNCREATE](#implement_dyncreate)|Permite a criação dinâmica e o acesso a informações em tempo de execução (devem ser usados na implementação da classe).|
|[IMPLEMENT_SERIAL](#implement_serial)|Permite serialização e acesso a informações de classe em tempo de execução (devem ser usadas na implementação da classe).|
|[Runtime_class](#runtime_class)|Retorna `CRuntimeClass` a estrutura que corresponde à classe nomeada.|

OLE frequentemente requer a criação dinâmica de objetos em tempo de execução. Por exemplo, um aplicativo de servidor OLE deve ser capaz de criar itens OLE dinamicamente em resposta a uma solicitação de um cliente. Da mesma forma, um servidor de automação deve ser capaz de criar itens em resposta a solicitações de clientes de automação.

A Biblioteca de Classes da Microsoft Foundation fornece duas macros específicas para o OLE.

### <a name="dynamic-creation-of-ole-objects"></a>Criação Dinâmica de Objetos OLE

|||
|-|-|
|[AFX_COMCTL32_IF_EXISTS](#afx_comctl32_if_exists)|Determina se a biblioteca Controles Comuns implementa a API especificada.|
|[AFX_COMCTL32_IF_EXISTS2](#afx_comctl32_if_exists2)|Determina se a biblioteca Controles Comuns implementa a API especificada.|
|[DECLARE_OLECREATE](#declare_olecreate)|Permite que objetos sejam criados através da automação OLE.|
|[DECLARE_OLECTLTYPE](#declare_olectltype)|Declara as `GetUserTypeNameID` `GetMiscStatus` funções e membros da sua classe de controle.|
|[DECLARE_PROPPAGEIDS](#declare_proppageids)|Declara que o controle OLE fornece uma lista de páginas de propriedade para exibir suas propriedades.|
|[IMPLEMENT_OLECREATE](#implement_olecreate)|Permite que objetos sejam criados pelo sistema OLE.|
|[IMPLEMENT_OLECTLTYPE](#implement_olectltype)|Implementa `GetUserTypeNameID` as `GetMiscStatus` funções e membros da sua classe de controle.|
|[IMPLEMENT_OLECREATE_FLAGS](#implement_olecreate_flags)|Esta macro ou [IMPLEMENT_OLECREATE](#implement_olecreate) devem aparecer no arquivo `DECLARE_OLECREATE`de implementação para qualquer classe que use . |

## <a name="afx_comctl32_if_exists"></a><a name="afx_comctl32_if_exists"></a>Afx_comctl32_if_exists

Determina se a biblioteca Controles Comuns implementa a API especificada.

### <a name="syntax"></a>Sintaxe

```
AFX_COMCTL32_IF_EXISTS(  proc );
```

### <a name="parameters"></a>Parâmetros

*proc*<br/>
Ponteiro para uma seqüência de terminadas nula contendo o nome da função ou especifica o valor ordinal da função. Se este parâmetro é um valor ordinal, deve estar na palavra de baixa ordem; a palavra de alta ordem deve ser zero. Este parâmetro deve estar em Unicode.

### <a name="remarks"></a>Comentários

Use esta macro para determinar se a biblioteca Controles Comuns a função especificada por *proc* (em vez de chamar [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress).

### <a name="requirements"></a>Requisitos

afxcomctl32.h, afxcomctl32.inl

## <a name="afx_comctl32_if_exists2"></a><a name="afx_comctl32_if_exists2"></a>AFX_COMCTL32_IF_EXISTS2

Determina se a biblioteca Controles Comuns implementa a API especificada (esta é a versão Unicode do [AFX_COMCTL32_IF_EXISTS](#afx_comctl32_if_exists)).

### <a name="syntax"></a>Sintaxe

```
AFX_COMCTL32_IF_EXISTS2( proc );
```

### <a name="parameters"></a>Parâmetros

*proc*<br/>
Ponteiro para uma seqüência de terminadas nula contendo o nome da função ou especifica o valor ordinal da função. Se este parâmetro é um valor ordinal, deve estar na palavra de baixa ordem; a palavra de alta ordem deve ser zero. Este parâmetro deve estar em Unicode.

### <a name="remarks"></a>Comentários

Use esta macro para determinar se a biblioteca Controles Comuns a função especificada por *proc* (em vez de chamar [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress). Esta macro é a versão Unicode do AFX_COMCTL32_IF_EXISTS.

### <a name="requirements"></a>Requisitos

afxcomctl32.h, afxcomctl32.inl

## <a name="declare_dynamic"></a><a name="declare_dynamic"></a>Declare_dynamic

Adiciona a capacidade de acessar informações em tempo de execução `CObject`sobre a classe de um objeto ao obter uma classe de .

```
DECLARE_DYNAMIC(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

Adicione a DECLARE_DYNAMIC macro ao módulo cabeçalho (.h) da classe e inclua esse módulo em todos os módulos .cpp que precisam de acesso a objetos desta classe.

Se você usar as macros DECLARE_ DYNAMIC e IMPLEMENT_DYNAMIC como descrito, você poderá usar a macro RUNTIME_CLASS e a `CObject::IsKindOf` função para determinar a classe de seus objetos em tempo de execução.

Se DECLARE_DYNAMIC for incluída na declaração da classe, IMPLEMENT_DYNAMIC deve ser incluído na implementação da classe.

Para obter mais informações sobre a macro DECLARE_DYNAMIC, consulte [CObject Class Topics](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

Veja o exemplo [de IMPLEMENT_DYNAMIC](#implement_dynamic).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="declare_dyncreate"></a><a name="declare_dyncreate"></a>Declare_dyncreate

Permite que `CObject`objetos de classes derivadas sejam criados dinamicamente no tempo de execução.

```
DECLARE_DYNCREATE(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

A estrutura usa essa capacidade de criar novos objetos dinamicamente. Por exemplo, a nova exibição criada quando você abre um novo documento. As classes de documento, visualização e quadro devem suportar a criação dinâmica porque a estrutura precisa criá-las dinamicamente.

Adicione a DECLARE_DYNCREATE macro no módulo .h para a classe e inclua esse módulo em todos os módulos .cpp que precisam de acesso a objetos desta classe.

Se DECLARE_DYNCREATE for incluída na declaração da classe, IMPLEMENT_DYNCREATE deve ser incluído na implementação da classe.

Para obter mais informações sobre a macro DECLARE_DYNCREATE, consulte [CObject Class Topics](../../mfc/using-cobject.md).

> [!NOTE]
> A DECLARE_DYNCREATE macro inclui todas as funcionalidades do DECLARE_DYNAMIC.

### <a name="example"></a>Exemplo

Veja o exemplo [de IMPLEMENT_DYNCREATE](#implement_dyncreate).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="declare_olectltype"></a><a name="declare_olectltype"></a>DECLARE_OLECTLTYPE

Declara as `GetUserTypeNameID` `GetMiscStatus` funções e membros da sua classe de controle.

### <a name="syntax"></a>Sintaxe

```
DECLARE_OLECTLTYPE( class_name )
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de controle.

### <a name="remarks"></a>Comentários

`GetUserTypeNameID`e `GetMiscStatus` são funções virtuais puras, declaradas em `COleControl`. Como essas funções são virtuais puras, elas devem ser substituídas em sua classe de controle. Além de DECLARE_OLECTLTYPE, você deve adicionar o IMPLEMENT_OLECTLTYPE macro à sua declaração de classe de controle.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="declare_proppageids"></a><a name="declare_proppageids"></a>DECLARE_PROPPAGEIDS

Declara que o controle OLE fornece uma lista de páginas de propriedade para exibir suas propriedades.

### <a name="syntax"></a>Sintaxe

```
DECLARE_PROPPAGEIDS( class_name )
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de controle que possui as páginas de propriedade.

### <a name="remarks"></a>Comentários

Use `DECLARE_PROPPAGEIDS` a macro no final da declaração da sua classe. Em seguida, no arquivo .cpp que define as funções `BEGIN_PROPPAGEIDS` do membro para a classe, use as entradas macro, macro para cada uma das páginas de propriedade do seu controle e a `END_PROPPAGEIDS` macro para declarar o fim da lista de páginas de propriedade.

Para obter mais informações sobre páginas de propriedade, consulte o artigo [ActiveX Controls: Property Pages](../mfc-activex-controls-property-pages.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="declare_serial"></a><a name="declare_serial"></a>Declare_serial

Gera o código de cabeçalho C++ necessário para uma `CObject`classe derivada que pode ser serializada.

```
DECLARE_SERIAL(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

Serialização é o processo de escrever ou ler o conteúdo de um objeto de e para um arquivo.

Use a DECLARE_SERIAL macro em um módulo .h e, em seguida, inclua esse módulo em todos os módulos .cpp que precisam de acesso a objetos desta classe.

Se DECLARE_SERIAL for incluída na declaração da classe, IMPLEMENT_SERIAL deve ser incluída na implementação da classe.

A DECLARE_SERIAL macro inclui todas as funcionalidades de DECLARE_DYNAMIC e DECLARE_DYNCREATE.

Você pode usar a AFX_API macro `CArchive` para exportar automaticamente o operador de extração para classes que usam as macros DECLARE_SERIAL e IMPLEMENT_SERIAL. Suporte as declarações de classe (localizadas no arquivo .h) com o seguinte código:

[!code-cpp[NVC_MFCCObjectSample#20](../../mfc/codesnippet/cpp/run-time-object-model-services_1.h)]

Para obter mais informações sobre a macro DECLARE_SERIAL, consulte [CObject Class Topics](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#21](../../mfc/codesnippet/cpp/run-time-object-model-services_2.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="implement_dynamic"></a><a name="implement_dynamic"></a>Implement_dynamic

Gera o código C++ `CObject`necessário para uma classe derivada dinâmica com acesso em tempo de execução ao nome da classe e posição dentro da hierarquia.

```
IMPLEMENT_DYNAMIC(class_name, base_class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe.

*base_class_name*<br/>
O nome da classe base.

### <a name="remarks"></a>Comentários

Use a macro IMPLEMENT_DYNAMIC em um módulo .cpp e, em seguida, vincule o código do objeto resultante apenas uma vez.

Para obter mais informações, consulte [CObject Class Topics](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#2](../../mfc/codesnippet/cpp/run-time-object-model-services_3.h)]

[!code-cpp[NVC_MFCCObjectSample#3](../../mfc/codesnippet/cpp/run-time-object-model-services_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="implement_dyncreate"></a><a name="implement_dyncreate"></a>Implement_dyncreate

Permite que `CObject`objetos de classes derivadas sejam criados dinamicamente no tempo de execução quando usados com a macro DECLARE_DYNCREATE.

```
IMPLEMENT_DYNCREATE(class_name, base_class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe.

*base_class_name*<br/>
O nome real da classe base.

### <a name="remarks"></a>Comentários

A estrutura usa essa capacidade de criar novos objetos dinamicamente, por exemplo, quando lê um objeto do disco durante a serialização. Adicione a IMPLEMENT_DYNCREATE macro no arquivo de implementação da classe. Para obter mais informações, consulte [CObject Class Topics](../../mfc/using-cobject.md).

Se você usar as macros DECLARE_DYNCREATE e IMPLEMENT_DYNCREATE, poderá `CObject::IsKindOf` usar a macro RUNTIME_CLASS e a função de membro para determinar a classe de seus objetos em tempo de execução.

Se DECLARE_DYNCREATE for incluída na declaração da classe, IMPLEMENT_DYNCREATE deve ser incluído na implementação da classe.

Observe que essa definição de macro invocará o construtor padrão para sua classe. Se um construtor não trivial for explicitamente implementado pela classe, ele também deve implementar explicitamente o construtor padrão também. O construtor padrão pode ser adicionado às seções de membros **privados** ou **protegidos** da classe para evitar que ele seja chamado de fora da implementação da classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#22](../../mfc/codesnippet/cpp/run-time-object-model-services_5.h)]

[!code-cpp[NVC_MFCCObjectSample#23](../../mfc/codesnippet/cpp/run-time-object-model-services_6.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="implement_olecreate_flags"></a><a name="implement_olecreate_flags"></a>Implement_olecreate_flags

Esta macro ou [IMPLEMENT_OLECREATE](#implement_olecreate) devem aparecer no arquivo de implementação para qualquer classe que use DECLARE_OLECREATE.

### <a name="syntax"></a>Sintaxe

```
IMPLEMENT_OLECREATE_FLAGS( class_name, external_name, nFlags,
    l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe.

*external_name*<br/>
O nome do objeto exposto a outras aplicações (incluído entre aspas).

*Nflags*<br/>
Contém uma ou mais das seguintes bandeiras:

- `afxRegInsertable`Permite que o controle apareça na caixa de diálogo Inserir objeto para objetos OLE.
- `afxRegApartmentThreading`Define o modelo de rosca no registro como ThreadingModel=Apartment.
- `afxRegFreeThreading`Define o modelo de rosca no registro como ThreadingModel=Free.

Você pode combinar `afxRegApartmentThreading` as `afxRegFreeThreading` duas bandeiras e definir ThreadingModel=Both. Consulte [InprocServer32](/windows/win32/com/inprocserver32) no SDK do Windows para obter mais informações sobre o registro do modelo de threading.

*l,* *w1,* *w2,* *b1,* *b2,* *b3,* *b4,* *b5,* *b6*, *b7*, *b8* Componentes do CLSID da classe.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Se você usar IMPLEMENT_OLECREATE_FLAGS, você pode especificar qual modelo de rosca o objeto suporta usando o parâmetro *nFlags.* Se você quiser suportar apenas o modelo de piso único, use IMPLEMENT_OLECREATE.

O nome externo é o identificador exposto a outras aplicações. Os aplicativos clientes usam o nome externo para solicitar um objeto desta classe a partir de um servidor de automação.

O ID de classe OLE é um identificador único de 128 bits para o objeto. Consiste de um **longo**, dois **WORD**s, e oito **BYTE**s, representado por *l*, *w1*, *w2*, e *b1* através *b8* na descrição da sintaxe. O Assistente de Aplicativo e os assistentes de código criam IDs de classe OLE exclusivos para você, conforme necessário.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="implement_olectltype"></a><a name="implement_olectltype"></a>IMPLEMENT_OLECTLTYPE

Implementa `GetUserTypeNameID` as `GetMiscStatus` funções e membros da sua classe de controle.

### <a name="syntax"></a>Sintaxe

```
DECLARE_OLECTLTYPE( class_name, idsUserTypeName, dwOleMisc )
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de controle.

*idsUserTypeName*<br/>
O ID de recurso de uma string contendo o nome externo do controle.

*dwOleMisc*<br/>
Uma enumeração contendo uma ou mais bandeiras. Para obter mais informações sobre essa enumeração, consulte [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) no SDK do Windows.

### <a name="remarks"></a>Comentários

Além de IMPLEMENT_OLECTLTYPE, você deve adicionar o DECLARE_OLECTLTYPE macro à sua declaração de classe de controle.

A `GetUserTypeNameID` função membro retorna a seqüência de recursos que identifica sua classe de controle. `GetMiscStatus`retorna os bits OLEMISC para o seu controle. Esta enumeração especifica uma coleção de configurações descrevendo características diversas do seu controle. Para obter uma descrição completa das configurações do OLEMISC, consulte [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) no SDK do Windows.

> [!NOTE]
> As configurações padrão usadas pelo ActiveX ControlWizard são: OLEMISC_ACTIVATEWHENVISIBLE, OLEMISC_SETCLIENTSITEFIRST, OLEMISC_INSIDEOUT, OLEMISC_CANTLINKINSIDE e OLEMISC_RECOMPOSEONRESIZE.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="implement_serial"></a><a name="implement_serial"></a>Implement_serial

Gera o código C++ `CObject`necessário para uma classe derivada dinâmica com acesso em tempo de execução ao nome da classe e posição dentro da hierarquia.

```
IMPLEMENT_SERIAL(class_name, base_class_name, wSchema)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe.

*base_class_name*<br/>
O nome da classe base.

*wSchema*<br/>
Um "número de versão" uint que será codificado no arquivo para permitir que um programa dedesserializador identifique e manuseie dados criados por versões anteriores do programa. O número do esquema da classe não deve ser -1.

### <a name="remarks"></a>Comentários

Use a macro IMPLEMENT_SERIAL em um módulo .cpp; em seguida, vincule o código do objeto resultante apenas uma vez.

Você pode usar a AFX_API macro `CArchive` para exportar automaticamente o operador de extração para classes que usam as macros DECLARE_SERIAL e IMPLEMENT_SERIAL. Suporte as declarações de classe (localizadas no arquivo .h) com o seguinte código:

[!code-cpp[NVC_MFCCObjectSample#20](../../mfc/codesnippet/cpp/run-time-object-model-services_1.h)]

Para obter mais informações, consulte os [Tópicos de Classe CObject](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#24](../../mfc/codesnippet/cpp/run-time-object-model-services_7.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="runtime_class"></a><a name="runtime_class"></a>Runtime_class

Obtém a estrutura de classe de tempo de execução a partir do nome de uma classe C++.

```
RUNTIME_CLASS(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe (não incluído entre aspas).

### <a name="remarks"></a>Comentários

RUNTIME_CLASS retorna um ponteiro para uma estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) para a classe especificada por *class_name*. Somente `CObject`classes derivadas declaradas com DECLARE_DYNAMIC, DECLARE_DYNCREATE ou DECLARE_SERIAL `CRuntimeClass` retornarão ponteiros para uma estrutura.

Para obter mais informações, consulte [CObject Class Topics](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#25](../../mfc/codesnippet/cpp/run-time-object-model-services_8.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="declare_olecreate"></a><a name="declare_olecreate"></a>Declare_olecreate

Permite que `CCmdTarget`objetos de classes derivadas sejam criados através da automação OLE.

```
DECLARE_OLECREATE(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

Essa macro permite que outros aplicativos habilitados para OLE criem objetos desse tipo.

Adicione a DECLARE_OLECREATE macro no módulo .h para a classe e, em seguida, inclua esse módulo em todos os módulos .cpp que precisam de acesso a objetos desta classe.

Se DECLARE_OLECREATE for incluída na declaração da classe, IMPLEMENT_OLECREATE deve ser incluída na implementação da classe. Uma declaração de classe usando DECLARE_OLECREATE também deve usar DECLARE_DYNCREATE ou DECLARE_SERIAL.

### <a name="requirements"></a>Requisitos

**Cabeçalho**: afxdisp.h

## <a name="implement_olecreate"></a><a name="implement_olecreate"></a>Implement_olecreate

Esta macro ou [IMPLEMENT_OLECREATE_FLAGS](#implement_olecreate_flags) devem aparecer no arquivo `DECLARE_OLECREATE`de implementação para qualquer classe que use .

```
IMPLEMENT_OLECREATE(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome real da classe.

*external_name*<br/>
O nome do objeto exposto a outras aplicações (incluído entre aspas).

*l,* *w1,* *w2,* *b1,* *b2,* *b3,* *b4,* *b5,* *b6*, *b7*, *b8* Componentes do CLSID da classe.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Se você usar IMPLEMENT_OLECREATE, por padrão, você suportará apenas o modelo de rosca única. Se você usar IMPLEMENT_OLECREATE_FLAGS, você pode especificar qual modelo de rosca o objeto suporta usando o parâmetro *nFlags.*

O nome externo é o identificador exposto a outras aplicações. Os aplicativos clientes usam o nome externo para solicitar um objeto desta classe a partir de um servidor de automação.

O ID de classe OLE é um identificador único de 128 bits para o objeto. Consiste de um **longo**, dois **WORD**s, e oito **BYTE**s, representado por *l*, *w1*, *w2*, e *b1* através *b8* na descrição da sintaxe. O Assistente de Aplicativo e os assistentes de código criam IDs de classe OLE exclusivos para você, conforme necessário.

### <a name="requirements"></a>Requisitos

**Cabeçalho**: afxdisp.h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Isolamento da biblioteca de controles comuns MFC](../isolation-of-the-mfc-common-controls-library.md)<br/>
[Chave CLSID](/windows/win32/com/clsid-key-hklm)
