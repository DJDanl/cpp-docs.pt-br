---
title: Serviços do modelo de objeto de tempo de execução
ms.date: 03/27/2019
helpviewer_keywords:
- run-time object model services macros
ms.assetid: 4a3e79df-2ee3-43a4-8193-20298828de85
ms.openlocfilehash: 63a82e3b05100f273be04a8718f2ecbb1510f06f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88844503"
---
# <a name="run-time-object-model-services"></a>Serviços do modelo de objeto de tempo de execução

As classes [CObject](../../mfc/reference/cobject-class.md) e [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) encapsulam vários serviços de objetos, incluindo acesso a informações de classe em tempo de execução, serialização e criação dinâmica de objetos. Todas as classes derivadas da `CObject` herança dessa funcionalidade.

O acesso às informações de classe em tempo de execução permite que você determine informações sobre a classe de um objeto em tempo de execução. A capacidade de determinar a classe de um objeto em tempo de execução é útil quando você precisa de verificação de tipo extra de argumentos de função e quando você deve escrever código de finalidade especial com base na classe de um objeto. Não há suporte para informações de classe em tempo de execução diretamente pela linguagem C++.

A serialização é o processo de gravar ou ler o conteúdo de um objeto de ou para um arquivo. Você pode usar a serialização para armazenar o conteúdo de um objeto mesmo após a saída do aplicativo. O objeto pode ser lido do arquivo quando o aplicativo é reiniciado. Esses objetos de dados são considerados "persistentes".

A criação dinâmica de objetos permite que você crie um objeto de uma classe especificada em tempo de execução. Por exemplo, documento, exibição e objetos de quadro devem dar suporte à criação dinâmica porque a estrutura precisa criá-los dinamicamente.

A tabela a seguir lista as macros do MFC que dão suporte a informações de classe de tempo de execução, serialização e criação dinâmica.

Para obter mais informações sobre esses serviços de objeto de tempo de execução e a serialização, consulte o artigo [CObject Class: Access Information-time de classe de tempo](../../mfc/accessing-run-time-class-information.md)de execução.

### <a name="run-time-object-model-services-macros"></a>Macros de serviços de modelo de objeto em tempo de execução

|Nome|Descrição|
|-|-|
|[DECLARE_DYNAMIC](#declare_dynamic)|Habilita o acesso às informações de classe de tempo de execução (deve ser usado na declaração de classe).|
|[DECLARE_DYNCREATE](#declare_dyncreate)|Permite a criação dinâmica e o acesso às informações de classe em tempo de execução (deve ser usado na declaração de classe).|
|[DECLARE_SERIAL](#declare_serial)|Habilita a serialização e o acesso às informações de classe em tempo de execução (deve ser usado na declaração de classe).|
|[IMPLEMENT_DYNAMIC](#implement_dynamic)|Habilita o acesso às informações de classe de tempo de execução (deve ser usado na implementação de classe).|
|[IMPLEMENT_DYNCREATE](#implement_dyncreate)|Permite a criação dinâmica e o acesso às informações de tempo de execução (deve ser usado na implementação da classe).|
|[IMPLEMENT_SERIAL](#implement_serial)|Permite a serialização e o acesso às informações de classe de tempo de execução (deve ser usado na implementação de classe).|
|[RUNTIME_CLASS](#runtime_class)|Retorna a `CRuntimeClass` estrutura que corresponde à classe nomeada.|

O OLE frequentemente requer a criação dinâmica de objetos em tempo de execução. Por exemplo, um aplicativo de servidor OLE deve ser capaz de criar itens OLE dinamicamente em resposta a uma solicitação de um cliente. Da mesma forma, um servidor de automação deve ser capaz de criar itens em resposta a solicitações de clientes de automação.

O biblioteca MFC fornece duas macros específicas ao OLE.

### <a name="dynamic-creation-of-ole-objects"></a>Criação dinâmica de objetos OLE

|Nome|Descrição|
|-|-|
|[AFX_COMCTL32_IF_EXISTS](#afx_comctl32_if_exists)|Determina se a biblioteca de controles comuns implementa a API especificada.|
|[AFX_COMCTL32_IF_EXISTS2](#afx_comctl32_if_exists2)|Determina se a biblioteca de controles comuns implementa a API especificada.|
|[DECLARE_OLECREATE](#declare_olecreate)|Permite que os objetos sejam criados por meio da automação OLE.|
|[DECLARE_OLECTLTYPE](#declare_olectltype)|Declara as `GetUserTypeNameID` funções de `GetMiscStatus` membro e de sua classe de controle.|
|[DECLARE_PROPPAGEIDS](#declare_proppageids)|Declara que o controle OLE fornece uma lista de páginas de propriedades para exibir suas propriedades.|
|[IMPLEMENT_OLECREATE](#implement_olecreate)|Permite que os objetos sejam criados pelo sistema OLE.|
|[IMPLEMENT_OLECTLTYPE](#implement_olectltype)|Implementa as `GetUserTypeNameID` `GetMiscStatus` funções de membro e de sua classe de controle.|
|[IMPLEMENT_OLECREATE_FLAGS](#implement_olecreate_flags)|Essa macro ou [IMPLEMENT_OLECREATE](#implement_olecreate) deve aparecer no arquivo de implementação para qualquer classe que usa `DECLARE_OLECREATE` . |

## <a name="afx_comctl32_if_exists"></a><a name="afx_comctl32_if_exists"></a> AFX_COMCTL32_IF_EXISTS

Determina se a biblioteca de controles comuns implementa a API especificada.

### <a name="syntax"></a>Sintaxe

```
AFX_COMCTL32_IF_EXISTS(  proc );
```

### <a name="parameters"></a>parâmetros

*processamento*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome da função ou especifica o valor ordinal da função. Se esse parâmetro for um valor ordinal, ele deverá estar na palavra de ordem inferior; a palavra de ordem superior deve ser zero. Esse parâmetro deve estar em Unicode.

### <a name="remarks"></a>Comentários

Use esta macro para determinar se a biblioteca de controles comuns da função especificada pelo *proc* (em vez de chamar [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress).

### <a name="requirements"></a>Requisitos

afxcomctl32. h, afxcomctl32. inl

## <a name="afx_comctl32_if_exists2"></a><a name="afx_comctl32_if_exists2"></a> AFX_COMCTL32_IF_EXISTS2

Determina se a biblioteca de controles comuns implementa a API especificada (esta é a versão Unicode do [AFX_COMCTL32_IF_EXISTS](#afx_comctl32_if_exists)).

### <a name="syntax"></a>Sintaxe

```
AFX_COMCTL32_IF_EXISTS2( proc );
```

### <a name="parameters"></a>parâmetros

*processamento*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome da função ou especifica o valor ordinal da função. Se esse parâmetro for um valor ordinal, ele deverá estar na palavra de ordem inferior; a palavra de ordem superior deve ser zero. Esse parâmetro deve estar em Unicode.

### <a name="remarks"></a>Comentários

Use esta macro para determinar se a biblioteca de controles comuns da função especificada pelo *proc* (em vez de chamar [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress). Esta macro é a versão Unicode do AFX_COMCTL32_IF_EXISTS.

### <a name="requirements"></a>Requisitos

afxcomctl32. h, afxcomctl32. inl

## <a name="declare_dynamic"></a><a name="declare_dynamic"></a> DECLARE_DYNAMIC

Adiciona a capacidade de acessar informações em tempo de execução sobre a classe de um objeto ao derivar uma classe de `CObject` .

```
DECLARE_DYNAMIC(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

Adicione a macro DECLARE_DYNAMIC ao módulo de cabeçalho (. h) para a classe e, em seguida, inclua esse módulo em todos os módulos. cpp que precisam de acesso a objetos dessa classe.

Se você usar as macros DECLARE_ DINÂMICAs e IMPLEMENT_DYNAMIC conforme descrito, poderá usar a macro RUNTIME_CLASS e a `CObject::IsKindOf` função para determinar a classe de seus objetos em tempo de execução.

Se DECLARE_DYNAMIC for incluído na declaração de classe, IMPLEMENT_DYNAMIC deverá ser incluído na implementação da classe.

Para obter mais informações sobre a macro DECLARE_DYNAMIC, consulte os [Tópicos da classe CObject](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [IMPLEMENT_DYNAMIC](#implement_dynamic).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="declare_dyncreate"></a><a name="declare_dyncreate"></a> DECLARE_DYNCREATE

Permite que objetos de `CObject` classes derivadas sejam criados dinamicamente em tempo de execução.

```
DECLARE_DYNCREATE(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

A estrutura usa essa capacidade para criar novos objetos dinamicamente. Por exemplo, a nova exibição criada quando você abre um novo documento. As classes Document, View e frame devem dar suporte à criação dinâmica porque a estrutura precisa criá-las dinamicamente.

Adicione a macro DECLARE_DYNCREATE no módulo. h da classe e, em seguida, inclua esse módulo em todos os módulos. cpp que precisam de acesso a objetos dessa classe.

Se DECLARE_DYNCREATE for incluído na declaração de classe, IMPLEMENT_DYNCREATE deverá ser incluído na implementação da classe.

Para obter mais informações sobre a macro DECLARE_DYNCREATE, consulte os [Tópicos da classe CObject](../../mfc/using-cobject.md).

> [!NOTE]
> A macro DECLARE_DYNCREATE inclui toda a funcionalidade do DECLARE_DYNAMIC.

### <a name="example"></a>Exemplo

Consulte o exemplo para [IMPLEMENT_DYNCREATE](#implement_dyncreate).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="declare_olectltype"></a><a name="declare_olectltype"></a> DECLARE_OLECTLTYPE

Declara as `GetUserTypeNameID` funções de `GetMiscStatus` membro e de sua classe de controle.

### <a name="syntax"></a>Sintaxe

```
DECLARE_OLECTLTYPE( class_name )
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de controle.

### <a name="remarks"></a>Comentários

`GetUserTypeNameID` e `GetMiscStatus` são funções virtuais puras, declaradas em `COleControl` . Como essas funções são virtuais puras, elas devem ser substituídas em sua classe de controle. Além de DECLARE_OLECTLTYPE, você deve adicionar a macro IMPLEMENT_OLECTLTYPE à sua declaração de classe de controle.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

## <a name="declare_proppageids"></a><a name="declare_proppageids"></a> DECLARE_PROPPAGEIDS

Declara que o controle OLE fornece uma lista de páginas de propriedades para exibir suas propriedades.

### <a name="syntax"></a>Sintaxe

```
DECLARE_PROPPAGEIDS( class_name )
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de controle que possui as páginas de propriedades.

### <a name="remarks"></a>Comentários

Use a `DECLARE_PROPPAGEIDS` macro no final da declaração de sua classe. Em seguida, no arquivo. cpp que define as funções de membro para a classe, use a `BEGIN_PROPPAGEIDS` macro, entradas de macro para cada uma das páginas de propriedades do controle e a `END_PROPPAGEIDS` macro para declarar o final da lista de páginas de propriedades.

Para obter mais informações sobre páginas de propriedades, consulte o artigo [controles ActiveX: páginas de propriedades](../mfc-activex-controls-property-pages.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

## <a name="declare_serial"></a><a name="declare_serial"></a> DECLARE_SERIAL

Gera o código de cabeçalho C++ necessário para uma `CObject` classe derivada que pode ser serializada.

```
DECLARE_SERIAL(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

A serialização é o processo de gravar ou ler o conteúdo de um objeto de e para um arquivo.

Use a macro DECLARE_SERIAL em um módulo. h e, em seguida, inclua esse módulo em todos os módulos. cpp que precisam de acesso a objetos dessa classe.

Se DECLARE_SERIAL for incluído na declaração de classe, IMPLEMENT_SERIAL deverá ser incluído na implementação da classe.

A macro DECLARE_SERIAL inclui toda a funcionalidade de DECLARE_DYNAMIC e DECLARE_DYNCREATE.

Você pode usar a macro AFX_API para exportar automaticamente o `CArchive` operador de extração para classes que usam as macros DECLARE_SERIAL e IMPLEMENT_SERIAL. Colchetes das declarações de classe (localizadas no arquivo. h) com o seguinte código:

[!code-cpp[NVC_MFCCObjectSample#20](../../mfc/codesnippet/cpp/run-time-object-model-services_1.h)]

Para obter mais informações sobre a macro DECLARE_SERIAL, consulte os [Tópicos da classe CObject](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#21](../../mfc/codesnippet/cpp/run-time-object-model-services_2.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="implement_dynamic"></a><a name="implement_dynamic"></a> IMPLEMENT_DYNAMIC

Gera o código C++ necessário para uma `CObject` classe derivada dinâmica com acesso em tempo de execução ao nome da classe e à posição dentro da hierarquia.

```
IMPLEMENT_DYNAMIC(class_name, base_class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe.

*base_class_name*<br/>
O nome da classe base.

### <a name="remarks"></a>Comentários

Use a macro IMPLEMENT_DYNAMIC em um módulo. cpp e, em seguida, vincule o código do objeto resultante apenas uma vez.

Para obter mais informações, consulte [CObject Class topics](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#2](../../mfc/codesnippet/cpp/run-time-object-model-services_3.h)]

[!code-cpp[NVC_MFCCObjectSample#3](../../mfc/codesnippet/cpp/run-time-object-model-services_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="implement_dyncreate"></a><a name="implement_dyncreate"></a> IMPLEMENT_DYNCREATE

Permite que objetos de `CObject` classes derivadas sejam criados dinamicamente em tempo de execução quando usados com a macro DECLARE_DYNCREATE.

```
IMPLEMENT_DYNCREATE(class_name, base_class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe.

*base_class_name*<br/>
O nome real da classe base.

### <a name="remarks"></a>Comentários

A estrutura usa essa capacidade de criar novos objetos dinamicamente, por exemplo, quando lê um objeto do disco durante a serialização. Adicione a macro IMPLEMENT_DYNCREATE no arquivo de implementação de classe. Para obter mais informações, consulte [CObject Class topics](../../mfc/using-cobject.md).

Se você usar as macros DECLARE_DYNCREATE e IMPLEMENT_DYNCREATE, poderá usar a macro RUNTIME_CLASS e a `CObject::IsKindOf` função de membro para determinar a classe de seus objetos em tempo de execução.

Se DECLARE_DYNCREATE for incluído na declaração de classe, IMPLEMENT_DYNCREATE deverá ser incluído na implementação da classe.

Observe que essa definição de macro invocará o construtor padrão para sua classe. Se um construtor não trivial for explicitamente implementado pela classe, também deverá implementar explicitamente o construtor padrão. O construtor padrão pode ser adicionado às seções da classe **`private`** ou do **`protected`** membro para impedir que ele seja chamado de fora da implementação da classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#22](../../mfc/codesnippet/cpp/run-time-object-model-services_5.h)]

[!code-cpp[NVC_MFCCObjectSample#23](../../mfc/codesnippet/cpp/run-time-object-model-services_6.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="implement_olecreate_flags"></a><a name="implement_olecreate_flags"></a> IMPLEMENT_OLECREATE_FLAGS

Essa macro ou [IMPLEMENT_OLECREATE](#implement_olecreate) deve aparecer no arquivo de implementação para qualquer classe que usa DECLARE_OLECREATE.

### <a name="syntax"></a>Sintaxe

```
IMPLEMENT_OLECREATE_FLAGS( class_name, external_name, nFlags,
    l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe.

*external_name*<br/>
O nome do objeto exposto a outros aplicativos (colocados entre aspas).

*nFlags*<br/>
Contém um ou mais dos seguintes sinalizadores:

- `afxRegInsertable` Permite que o controle apareça na caixa de diálogo Inserir objeto para objetos OLE.
- `afxRegApartmentThreading` Define o modelo de threading no registro como ThreadingModel = Apartment.
- `afxRegFreeThreading` Define o modelo de threading no registro como ThreadingModel = Free.

Você pode combinar os dois sinalizadores `afxRegApartmentThreading` e `afxRegFreeThreading` definir ThreadingModel = ambos. Consulte [InprocServer32](/windows/win32/com/inprocserver32) no SDK do Windows para obter mais informações sobre o registro do modelo de Threading.

os componentes *l*, *W1*, *W2*, *B1*, *B2*, *B3*, *B4*, *B5*, *B6*, *B7*e *B8* do CLSID da classe.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Se você usar IMPLEMENT_OLECREATE_FLAGS, poderá especificar o modelo de Threading ao qual o objeto dá suporte usando o parâmetro *nFlags* . Se você quiser dar suporte apenas ao modelo de treading único, use IMPLEMENT_OLECREATE.

O nome externo é o identificador exposto a outros aplicativos. Os aplicativos cliente usam o nome externo para solicitar um objeto dessa classe de um servidor de automação.

A ID da classe OLE é um identificador exclusivo de 128 bits para o objeto. Ele consiste em um **`long`** , duas **palavras**s e oito **bytes**s, conforme representado por *l*, *W1*, *W2*e *B1* a *B8* na descrição da sintaxe. O assistente de aplicativo e os assistentes de código criam IDs de classe OLE exclusivas para você, conforme necessário.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="implement_olectltype"></a><a name="implement_olectltype"></a> IMPLEMENT_OLECTLTYPE

Implementa as `GetUserTypeNameID` `GetMiscStatus` funções de membro e de sua classe de controle.

### <a name="syntax"></a>Sintaxe

```
DECLARE_OLECTLTYPE( class_name, idsUserTypeName, dwOleMisc )
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de controle.

*idsUserTypeName*<br/>
A ID de recurso de uma cadeia de caracteres que contém o nome externo do controle.

*dwOleMisc*<br/>
Uma enumeração que contém um ou mais sinalizadores. Para obter mais informações sobre essa enumeração, consulte [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) no SDK do Windows.

### <a name="remarks"></a>Comentários

Além de IMPLEMENT_OLECTLTYPE, você deve adicionar a macro DECLARE_OLECTLTYPE à sua declaração de classe de controle.

A `GetUserTypeNameID` função membro retorna a cadeia de caracteres de recurso que identifica sua classe de controle. `GetMiscStatus` Retorna os bits OLEMISC para seu controle. Essa enumeração Especifica uma coleção de configurações que descrevem características diversas de seu controle. Para obter uma descrição completa das configurações de OLEMISC, consulte [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) no SDK do Windows.

> [!NOTE]
> As configurações padrão usadas pelo ControlWizard ActiveX são: OLEMISC_ACTIVATEWHENVISIBLE, OLEMISC_SETCLIENTSITEFIRST, OLEMISC_INSIDEOUT, OLEMISC_CANTLINKINSIDE e OLEMISC_RECOMPOSEONRESIZE.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

## <a name="implement_serial"></a><a name="implement_serial"></a> IMPLEMENT_SERIAL

Gera o código C++ necessário para uma `CObject` classe derivada dinâmica com acesso em tempo de execução ao nome da classe e à posição dentro da hierarquia.

```
IMPLEMENT_SERIAL(class_name, base_class_name, wSchema)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe.

*base_class_name*<br/>
O nome da classe base.

*wSchema*<br/>
Um "número de versão" UINT que será codificado no arquivo para habilitar um programa de desserialização para identificar e manipular os dados criados por versões anteriores do programa. O número de esquema de classe não deve ser-1.

### <a name="remarks"></a>Comentários

Use a macro IMPLEMENT_SERIAL em um módulo. cpp; em seguida, vincule o código do objeto resultante apenas uma vez.

Você pode usar a macro AFX_API para exportar automaticamente o `CArchive` operador de extração para classes que usam as macros DECLARE_SERIAL e IMPLEMENT_SERIAL. Colchetes das declarações de classe (localizadas no arquivo. h) com o seguinte código:

[!code-cpp[NVC_MFCCObjectSample#20](../../mfc/codesnippet/cpp/run-time-object-model-services_1.h)]

Para obter mais informações, consulte os [Tópicos da classe CObject](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#24](../../mfc/codesnippet/cpp/run-time-object-model-services_7.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="runtime_class"></a><a name="runtime_class"></a> RUNTIME_CLASS

Obtém a estrutura de classe de tempo de execução do nome de uma classe C++.

```
RUNTIME_CLASS(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe (não entre aspas).

### <a name="remarks"></a>Comentários

RUNTIME_CLASS retorna um ponteiro para uma estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) para a classe especificada por *class_name*. Somente as `CObject` classes derivadas declaradas com DECLARE_DYNAMIC, DECLARE_DYNCREATE ou DECLARE_SERIAL retornarão ponteiros para uma `CRuntimeClass` estrutura.

Para obter mais informações, consulte [CObject Class topics](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#25](../../mfc/codesnippet/cpp/run-time-object-model-services_8.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="declare_olecreate"></a><a name="declare_olecreate"></a> DECLARE_OLECREATE

Permite que objetos de `CCmdTarget` classes derivadas sejam criados por meio da automação OLE.

```
DECLARE_OLECREATE(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

Essa macro permite que outros aplicativos habilitados para OLE criem objetos desse tipo.

Adicione a macro DECLARE_OLECREATE no módulo. h da classe e, em seguida, inclua esse módulo em todos os módulos. cpp que precisam de acesso a objetos dessa classe.

Se DECLARE_OLECREATE for incluído na declaração de classe, IMPLEMENT_OLECREATE deverá ser incluído na implementação da classe. Uma declaração de classe usando DECLARE_OLECREATE também deve usar DECLARE_DYNCREATE ou DECLARE_SERIAL.

### <a name="requirements"></a>Requisitos

**Cabeçalho**: AFXDISP. h

## <a name="implement_olecreate"></a><a name="implement_olecreate"></a> IMPLEMENT_OLECREATE

Essa macro ou [IMPLEMENT_OLECREATE_FLAGS](#implement_olecreate_flags) deve aparecer no arquivo de implementação para qualquer classe que usa `DECLARE_OLECREATE` .

```
IMPLEMENT_OLECREATE(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome real da classe.

*external_name*<br/>
O nome do objeto exposto a outros aplicativos (colocados entre aspas).

os componentes *l*, *W1*, *W2*, *B1*, *B2*, *B3*, *B4*, *B5*, *B6*, *B7*e *B8* do CLSID da classe.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Se você usar IMPLEMENT_OLECREATE, por padrão, oferecerá suporte apenas ao modelo de Threading único. Se você usar IMPLEMENT_OLECREATE_FLAGS, poderá especificar o modelo de Threading ao qual o objeto dá suporte usando o parâmetro *nFlags* .

O nome externo é o identificador exposto a outros aplicativos. Os aplicativos cliente usam o nome externo para solicitar um objeto dessa classe de um servidor de automação.

A ID da classe OLE é um identificador exclusivo de 128 bits para o objeto. Ele consiste em um **`long`** , duas **palavras**s e oito **bytes**s, conforme representado por *l*, *W1*, *W2*e *B1* a *B8* na descrição da sintaxe. O assistente de aplicativo e os assistentes de código criam IDs de classe OLE exclusivas para você, conforme necessário.

### <a name="requirements"></a>Requisitos

**Cabeçalho**: AFXDISP. h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Isolamento da biblioteca de controles comuns do MFC](../isolation-of-the-mfc-common-controls-library.md)<br/>
[Chave CLSID](/windows/win32/com/clsid-key-hklm)
