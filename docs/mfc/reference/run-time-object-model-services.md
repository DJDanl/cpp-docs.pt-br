---
title: Serviços do modelo de objeto de tempo de execução
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.macros
helpviewer_keywords:
- run-time object model services macros
ms.assetid: 4a3e79df-2ee3-43a4-8193-20298828de85
ms.openlocfilehash: fce6fb938b501da7bc9251de51c71714e4613fd5
ms.sourcegitcommit: bd637e9c39650cfd530520ea978a22fa4caa0e42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/07/2019
ms.locfileid: "55850279"
---
# <a name="run-time-object-model-services"></a>Serviços do modelo de objeto de tempo de execução

As classes [CObject](../../mfc/reference/cobject-class.md) e [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) encapsular vários serviços de objeto, incluindo o acesso a informações de classe de tempo de execução, a serialização e a criação de objeto dinâmico. Todas as classes derivadas de `CObject` herdam essa funcionalidade.

Acesso a informações de classe de tempo de execução permite que você determine informações sobre uma classe de objeto em tempo de execução. A capacidade de determinar a classe de um objeto em tempo de execução é útil quando você precisar extraverificação de tipo de argumentos de função e você deve escrever o código de finalidade especial com base na classe de um objeto. Não há suporte para informações de classe de tempo de execução diretamente pela linguagem C++.

A serialização é o processo de escrever ou ler o conteúdo de um objeto para ou de um arquivo. Você pode usar a serialização para armazenar o conteúdo de um objeto mesmo depois que o aplicativo é encerrado. O objeto, em seguida, pode ser lidos do arquivo quando o aplicativo for reiniciado. Esses objetos de dados são considerados "persistentes".

Criação de objeto dinâmico permite que você crie um objeto de uma classe especificada em tempo de execução. Por exemplo, documento, exibição e objetos de quadro devem dar suporte a criação dinâmica porque a estrutura precisa criá-los dinamicamente.

A tabela a seguir lista as macros do MFC que oferecem suporte a informações de classe de tempo de execução, a serialização e a criação dinâmica.

Para obter mais informações sobre esses serviços de objeto de tempo de execução e a serialização, consulte o artigo [classe CObject: Acessando informações da classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).

### <a name="run-time-object-model-services-macros"></a>Macros de serviços do modelo de objeto de tempo de execução

|||
|-|-|
|[DECLARE_DYNAMIC](#declare_dynamic)|Permite acesso a informações de classe de tempo de execução (deve ser usado na declaração de classe).|
|[DECLARE_DYNCREATE](#declare_dyncreate)|Permite a criação dinâmica e acesso a informações de classe de tempo de execução (deve ser usado na declaração de classe).|
|[DECLARE_SERIAL](#declare_serial)|Habilita a serialização e o acesso a informações de classe de tempo de execução (deve ser usado na declaração de classe).|
|[IMPLEMENT_DYNAMIC](#implement_dynamic)|Permite acesso a informações de classe de tempo de execução (deve ser usada na implementação da classe).|
|[IMPLEMENT_DYNCREATE](#implement_dyncreate)|Permite a criação dinâmica e acesso a informações de tempo de execução (deve ser usada na implementação da classe).|
|[IMPLEMENT_SERIAL](#implement_serial)|Permite que a serialização e o acesso a informações de classe de tempo de execução (deve ser usada na implementação da classe).|
|[RUNTIME_CLASS](#runtime_class)|Retorna o `CRuntimeClass` estrutura que corresponde à classe nomeada.|

OLE com frequência requer a criação dinâmica de objetos em tempo de execução. Por exemplo, um aplicativo de servidor OLE deve ser capaz de criar itens OLE dinamicamente em resposta a uma solicitação de um cliente. Da mesma forma, um servidor de automação deve ser capaz de criar itens em resposta a solicitações de clientes de automação.

A biblioteca Microsoft Foundation Class fornece duas macros específicas para OLE.

### <a name="dynamic-creation-of-ole-objects"></a>Criação dinâmica de objetos OLE

|||
|-|-|
|[AFX_COMCTL32_IF_EXISTS](#afx_comctl32_if_exists)|Determina se a biblioteca de controles comuns implementa a API especificada.|
|[AFX_COMCTL32_IF_EXISTS2](#afx_comctl32_if_exists2)|Determina se a biblioteca de controles comuns implementa a API especificada.|
|[DECLARE_OLECREATE](#declare_olecreate)|Permite que os objetos a serem criados por meio da automação OLE.|
|[DECLARE_OLECTLTYPE](#declare_olectltype)|Declara o `GetUserTypeNameID` e `GetMiscStatus` funções de membro de sua classe de controle.|
|[DECLARE_PROPPAGEIDS](#declare_proppageids)|Declara que o controle OLE fornece uma lista das páginas de propriedades para exibir suas propriedades.|
|[IMPLEMENT_OLECREATE](#implement_olecreate)|Permite que os objetos a serem criados pelo sistema OLE.|
|[IMPLEMENT_OLECTLTYPE](#implement_olectltype)|Implementa o `GetUserTypeNameID` e `GetMiscStatus` funções de membro de sua classe de controle.|
|[IMPLEMENT_OLECREATE_FLAGS](#implement_olecreate_flags)|Qualquer esta macro ou [IMPLEMENT_OLECREATE](#implement_olecreate) deve aparecer no arquivo de implementação para qualquer classe que usa `DECLARE_OLECREATE`. |

## <a name="afx_comctl32_if_exists"></a> AFX_COMCTL32_IF_EXISTS

Determina se a biblioteca de controles comuns implementa a API especificada.

### <a name="syntax"></a>Sintaxe

  ```
AFX_COMCTL32_IF_EXISTS(  proc );
```

### <a name="parameters"></a>Parâmetros

*proc*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome da função, ou especifica o valor ordinal da função. Se esse parâmetro é um valor ordinal, ele deverá ser a palavra de ordem inferior; a palavra de ordem superior deve ser zero. Esse parâmetro deve ser em Unicode.

### <a name="remarks"></a>Comentários

Usar essa macro para determinar se a biblioteca de controles comuns a função especificada por *proc* (em vez de chamar [GetProcAddress](/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

### <a name="requirements"></a>Requisitos

afxcomctl32.h, afxcomctl32.inl

## <a name="afx_comctl32_if_exists2"></a>  AFX_COMCTL32_IF_EXISTS2

Determina se a biblioteca de controles comuns implementa a API especificada (Isso é a versão Unicode [AFX_COMCTL32_IF_EXISTS](#afx_comctl32_if_exists)).

### <a name="syntax"></a>Sintaxe

```
AFX_COMCTL32_IF_EXISTS2( proc );
```

### <a name="parameters"></a>Parâmetros

*proc*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome da função, ou especifica o valor ordinal da função. Se esse parâmetro é um valor ordinal, ele deverá ser a palavra de ordem inferior; a palavra de ordem superior deve ser zero. Esse parâmetro deve ser em Unicode.

### <a name="remarks"></a>Comentários

Usar essa macro para determinar se a biblioteca de controles comuns a função especificada por *proc* (em vez de chamar [GetProcAddress](/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Essa macro é a versão Unicode de AFX_COMCTL32_IF_EXISTS.

### <a name="requirements"></a>Requisitos

afxcomctl32.h, afxcomctl32.inl

##  <a name="declare_dynamic"></a>  DECLARE_DYNAMIC

Adiciona a capacidade de acessar informações de tempo de execução sobre uma classe de objeto ao derivar uma classe de `CObject`.

```
DECLARE_DYNAMIC(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

Adicione a macro DECLARE_DYNAMIC o módulo de cabeçalho (. h) para a classe e incluir o módulo em todos os módulos. cpp que precisam acessar objetos dessa classe.

Se você usar as macros DECLARE_ dinâmico e IMPLEMENT_DYNAMIC conforme descrito, você pode usar a macro RUNTIME_CLASS e o `CObject::IsKindOf` função para determinar a classe dos objetos de tempo de execução.

Se DECLARE_DYNAMIC estiver incluído na declaração de classe, IMPLEMENT_DYNAMIC deve ser incluído na implementação da classe.

Para obter mais informações sobre a macro DECLARE_DYNAMIC, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [IMPLEMENT_DYNAMIC](#implement_dynamic).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="declare_dyncreate"></a>  DECLARE_DYNCREATE

Permite que objetos de `CObject`-criada dinamicamente em tempo de execução de classes derivadas.

```
DECLARE_DYNCREATE(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

A estrutura usa essa capacidade para criar novos objetos dinamicamente. Por exemplo, o novo modo de exibição criado quando você abre um novo documento. Classes de quadro, modo de exibição e documento devem dar suporte a criação dinâmica porque a estrutura precisa criá-los dinamicamente.

Adicione a macro DECLARE_DYNCREATE no módulo. h para a classe e incluir o módulo em todos os módulos. cpp que precisam acessar objetos dessa classe.

Se DECLARE_DYNCREATE estiver incluído na declaração de classe, IMPLEMENT_DYNCREATE deve ser incluído na implementação da classe.

Para obter mais informações sobre a macro DECLARE_DYNCREATE, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).

> [!NOTE]
>  A macro DECLARE_DYNCREATE inclui toda a funcionalidade do DECLARE_DYNAMIC.

### <a name="example"></a>Exemplo

Veja o exemplo de [IMPLEMENT_DYNCREATE](#implement_dyncreate).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="declareolectltype"></a>DECLARE_OLECTLTYPE

Declara o `GetUserTypeNameID` e `GetMiscStatus` funções de membro de sua classe de controle.

### <a name="syntax"></a>Sintaxe

```
DECLARE_OLECTLTYPE( class_name )
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe do controle.

### <a name="remarks"></a>Comentários

`GetUserTypeNameID` e `GetMiscStatus` são funções virtuais puras, declaradas em `COleControl`. Como essas funções são puras virtual, eles devem ser substituídos em sua classe de controle. Além de DECLARE_OLECTLTYPE, você deve adicionar a macro IMPLEMENT_OLECTLTYPE à declaração de classe de controle.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

## <a name="declareproppageids"></a>DECLARE_PROPPAGEIDS

Declara que o controle OLE fornece uma lista das páginas de propriedades para exibir suas propriedades.

### <a name="syntax"></a>Sintaxe

```
DECLARE_PROPPAGEIDS( class_name )
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe do controle que possui as páginas de propriedades.

### <a name="remarks"></a>Comentários

Use o `DECLARE_PROPPAGEIDS` macro no final de sua declaração de classe. Em seguida, no arquivo. cpp que define as funções de membro da classe, use o `BEGIN_PROPPAGEIDS` macro, entradas de macro para cada uma das páginas de propriedades do seu controle e o `END_PROPPAGEIDS` macro para declarar o fim da lista de página de propriedades.

Para obter mais informações sobre páginas de propriedades, consulte o artigo [controles ActiveX: Páginas de propriedade](../mfc-activex-controls-property-pages.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="declare_serial"></a>  DECLARE_SERIAL

Gera o código de cabeçalho C++ necessário para um `CObject`-derivado da classe que pode ser serializado.

```
DECLARE_SERIAL(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

A serialização é o processo de gravar ou ler o conteúdo de um objeto e de um arquivo.

Use a macro DECLARE_SERIAL em um módulo. h e, em seguida, inclua esse módulo em todos os módulos. cpp que precisam acessar objetos dessa classe.

Se DECLARE_SERIAL estiver incluído na declaração de classe, IMPLEMENT_SERIAL deve ser incluído na implementação da classe.

A macro DECLARE_SERIAL inclui toda a funcionalidade de DECLARE_DYNAMIC e DECLARE_DYNCREATE.

Você pode usar a macro AFX_API para exportar automaticamente o `CArchive` operador de extração para classes que usam as macros DECLARE_SERIAL e IMPLEMENT_SERIAL. Colchete as declarações de classe (localizadas no arquivo. h) com o código a seguir:

[!code-cpp[NVC_MFCCObjectSample#20](../../mfc/codesnippet/cpp/run-time-object-model-services_1.h)]

Para obter mais informações sobre a macro DECLARE_SERIAL, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#21](../../mfc/codesnippet/cpp/run-time-object-model-services_2.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="implement_dynamic"></a>  IMPLEMENT_DYNAMIC

Gera o código de C++ necessário para dinâmico `CObject`-classe com acesso de tempo de execução é derivada do nome de classe e a posição dentro da hierarquia.

```
IMPLEMENT_DYNAMIC(class_name, base_class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe.

*base_class_name*<br/>
O nome da classe base.

### <a name="remarks"></a>Comentários

Use a macro IMPLEMENT_DYNAMIC em um módulo. cpp e, em seguida, vincular o código resultante do objeto apenas uma vez.

Para obter mais informações, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#2](../../mfc/codesnippet/cpp/run-time-object-model-services_3.h)]

[!code-cpp[NVC_MFCCObjectSample#3](../../mfc/codesnippet/cpp/run-time-object-model-services_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="implement_dyncreate"></a>  IMPLEMENT_DYNCREATE

Permite que objetos de `CObject`-derivadas de classes a serem criados dinamicamente na execução de tempo quando usado com a macro DECLARE_DYNCREATE.

```
IMPLEMENT_DYNCREATE(class_name, base_class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe.

*base_class_name*<br/>
O nome real da classe base.

### <a name="remarks"></a>Comentários

A estrutura usa essa capacidade para criar novos objetos dinamicamente, por exemplo, quando ele lê um objeto do disco durante a serialização. Adicione a macro IMPLEMENT_DYNCREATE no arquivo de implementação de classe. Para obter mais informações, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).

Se você usar as macros DECLARE_DYNCREATE e IMPLEMENT_DYNCREATE, você pode usar a macro RUNTIME_CLASS e o `CObject::IsKindOf` a função de membro para determinar a classe dos objetos de tempo de execução.

Se DECLARE_DYNCREATE estiver incluído na declaração de classe, IMPLEMENT_DYNCREATE deve ser incluído na implementação da classe.

Observe que essa definição de macro invocará o construtor padrão para a sua classe. Se um construtor não trivial é implementado explicitamente pela classe, ele deverá implementar explicitamente construtor padrão. O construtor padrão pode ser adicionado à classe de **privados** ou **protegido** seções de membro para impedir que ela está sendo chamado de fora a implementação da classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#22](../../mfc/codesnippet/cpp/run-time-object-model-services_5.h)]

[!code-cpp[NVC_MFCCObjectSample#23](../../mfc/codesnippet/cpp/run-time-object-model-services_6.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="implement_olecreate_flags"></a>  IMPLEMENT_OLECREATE_FLAGS

Qualquer esta macro ou [IMPLEMENT_OLECREATE](#implement_olecreate) deve aparecer no arquivo de implementação para qualquer classe que usa DECLARE_OLECREATE.

### <a name="syntax"></a>Sintaxe

```
IMPLEMENT_OLECREATE_FLAGS( class_name, external_name, nFlags,
    l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe.

*external_name*<br/>
O nome do objeto exposto a outros aplicativos (entre aspas).

*nFlags*<br/>
Contém um ou mais dos seguintes sinalizadores:

   - `afxRegInsertable` Permite que o controle apareça na caixa de diálogo Inserir objeto para objetos OLE.
   - `afxRegApartmentThreading` Define o modelo de threading no registro para ThreadingModel = Apartment.
   - `afxRegFreeThreading` Define o modelo de threading no registro para ThreadingModel = gratuito.

         You can combine the two flags `afxRegApartmentThreading` and `afxRegFreeThreading` to set ThreadingModel=Both. See [InprocServer32](/windows/desktop/com/inprocserver32) in the Windows SDK for more information on threading model registration.

*l*, *w1*, *w2*, *b1*, *b2*, *b3*, *b4* , *b5*, *b6*, *b7*, *M8* componentes do CLSID da classe.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Se você usar IMPLEMENT_OLECREATE_FLAGS, você pode especificar qual modelo de threading que dá suporte ao seu objeto usando o *nFlags* parâmetro. Se você quiser dar suporte a apenas o modelo de threading de única, use IMPLEMENT_OLECREATE.

O nome externo é o identificador exposto a outros aplicativos. Aplicativos clientes usam o nome externo para solicitar um objeto dessa classe de um servidor de automação.

A ID de classe OLE é um identificador exclusivo de 128 bits para o objeto. Ele consiste em uma **longo**, dois **WORD**s e oito **bytes**s, conforme representado por *l*, *w1*, *w2*, e *b1* por meio do *M8* na descrição de sintaxe. Os assistentes de código e o Assistente de aplicativo criar IDs exclusivas de classe OLE para você conforme necessário.

### <a name="requirements"></a>Requisitos

**Header:** afxdisp.h

## <a name="implement_olecreate"></a> IMPLEMENT_OLECTLTYPE

Implementa o `GetUserTypeNameID` e `GetMiscStatus` funções de membro de sua classe de controle.

### <a name="syntax"></a>Sintaxe

```
DECLARE_OLECTLTYPE( class_name, idsUserTypeName, dwOleMisc )
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe do controle.

*idsUserTypeName*<br/>
A ID de recurso de uma cadeia de caracteres que contém o nome externo do controle.

*dwOleMisc*<br/>
Uma enumeração que contém um ou mais sinalizadores. Para obter mais informações sobre essa enumeração, consulte [OLEMISC](/windows/desktop/api/oleidl/ne-oleidl-tagolemisc) no SDK do Windows.

### <a name="remarks"></a>Comentários

Além de IMPLEMENT_OLECTLTYPE, você deve adicionar a macro DECLARE_OLECTLTYPE à declaração de classe de controle.

O `GetUserTypeNameID` função membro retorna a cadeia de caracteres de recurso que identifica a sua classe de controle. `GetMiscStatus` Retorna os bits OLEMISC para o seu controle. Esta enumeração Especifica uma coleção de configurações que descrevem diversas características do seu controle. Para obter uma descrição completa das configurações OLEMISC, consulte [OLEMISC](/windows/desktop/api/oleidl/ne-oleidl-tagolemisc) no SDK do Windows.

> [!NOTE]
>  As configurações padrão usadas pelo ControlWizard ActiveX são: OLEMISC_ACTIVATEWHENVISIBLE, OLEMISC_SETCLIENTSITEFIRST, OLEMISC_INSIDEOUT, OLEMISC_CANTLINKINSIDE e OLEMISC_RECOMPOSEONRESIZE.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="implement_serial"></a>  IMPLEMENT_SERIAL

Gera o código de C++ necessário para dinâmico `CObject`-classe com acesso de tempo de execução é derivada do nome de classe e a posição dentro da hierarquia.

```
IMPLEMENT_SERIAL(class_name, base_class_name, wSchema)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe.

*base_class_name*<br/>
O nome da classe base.

*wSchema*<br/>
Anteriormente, um UINT "número de versão" que será codificado no arquivo para habilitar um programa desserializar identifique e manipule os dados criados pelo programa versões. O número de esquema de classe não deve ser -1.

### <a name="remarks"></a>Comentários

Use a macro IMPLEMENT_SERIAL em um módulo. cpp; em seguida, vincule o código resultante do objeto apenas uma vez.

Você pode usar a macro AFX_API para exportar automaticamente o `CArchive` operador de extração para classes que usam as macros DECLARE_SERIAL e IMPLEMENT_SERIAL. Colchete as declarações de classe (localizadas no arquivo. h) com o código a seguir:

[!code-cpp[NVC_MFCCObjectSample#20](../../mfc/codesnippet/cpp/run-time-object-model-services_1.h)]

Para obter mais informações, consulte o [tópicos de classe de CObject](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#24](../../mfc/codesnippet/cpp/run-time-object-model-services_7.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="runtime_class"></a>  RUNTIME_CLASS

Obtém a estrutura de classe de tempo de execução do nome de uma classe C++.

```
RUNTIME_CLASS(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe (não é colocado entre aspas).

### <a name="remarks"></a>Comentários

RUNTIME_CLASS retorna um ponteiro para um [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura para a classe especificada por *class_name*. Somente `CObject`-classes derivadas declaradas com DECLARE_DYNAMIC, DECLARE_DYNCREATE ou DECLARE_SERIAL retornarão ponteiros para um `CRuntimeClass` estrutura.

Para obter mais informações, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#25](../../mfc/codesnippet/cpp/run-time-object-model-services_8.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="declare_olecreate"></a>  DECLARE_OLECREATE

Permite que objetos de `CCmdTarget`-derivadas de classes a serem criados por meio da automação OLE.

```
DECLARE_OLECREATE(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe.

### <a name="remarks"></a>Comentários

Esta macro permite que outros aplicativos habilitados para OLE criar objetos desse tipo.

Adicione a macro DECLARE_OLECREATE no módulo. h para a classe e, em seguida, inclua esse módulo em todos os módulos. cpp que precisam acessar objetos dessa classe.

Se DECLARE_OLECREATE estiver incluído na declaração de classe, IMPLEMENT_OLECREATE deve ser incluído na implementação da classe. Uma declaração de classe usando DECLARE_OLECREATE também deve usar DECLARE_DYNCREATE ou DECLARE_SERIAL.

### <a name="requirements"></a>Requisitos

**Header**: afxdisp.h

##  <a name="implement_olecreate"></a>  IMPLEMENT_OLECREATE

Qualquer esta macro ou [IMPLEMENT_OLECREATE_FLAGS](#implement_olecreate_flags) deve aparecer no arquivo de implementação para qualquer classe que usa `DECLARE_OLECREATE`.

```
IMPLEMENT_OLECREATE(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome real da classe.

*external_name*<br/>
O nome do objeto exposto a outros aplicativos (entre aspas).

*l*, *w1*, *w2*, *b1*, *b2*, *b3*, *b4* , *b5*, *b6*, *b7*, *M8* componentes do CLSID da classe.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Se você usar IMPLEMENT_OLECREATE, por padrão, você dá suporte a apenas o modelo de threading único. Se você usar IMPLEMENT_OLECREATE_FLAGS, você pode especificar qual modelo de threading que dá suporte ao seu objeto usando o *nFlags* parâmetro.

O nome externo é o identificador exposto a outros aplicativos. Aplicativos clientes usam o nome externo para solicitar um objeto dessa classe de um servidor de automação.

A ID de classe OLE é um identificador exclusivo de 128 bits para o objeto. Ele consiste em uma **longo**, dois **WORD**s e oito **bytes**s, conforme representado por *l*, *w1*, *w2*, e *b1* por meio do *M8* na descrição de sintaxe. Os assistentes de código e o Assistente de aplicativo criar IDs exclusivas de classe OLE para você conforme necessário.

### <a name="requirements"></a>Requisitos

**Header**: afxdisp.h

## <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Isolamento da biblioteca de controles comuns MFC](../isolation-of-the-mfc-common-controls-library.md)<br/>
[Chave CLSID](/windows/desktop/com/clsid-key-hklm)

