---
title: Classe CGdiObject
ms.date: 11/04/2016
f1_keywords:
- CGdiObject
- AFXWIN/CGdiObject
- AFXWIN/CGdiObject::CGdiObject
- AFXWIN/CGdiObject::Attach
- AFXWIN/CGdiObject::CreateStockObject
- AFXWIN/CGdiObject::DeleteObject
- AFXWIN/CGdiObject::DeleteTempMap
- AFXWIN/CGdiObject::Detach
- AFXWIN/CGdiObject::FromHandle
- AFXWIN/CGdiObject::GetObject
- AFXWIN/CGdiObject::GetObjectType
- AFXWIN/CGdiObject::GetSafeHandle
- AFXWIN/CGdiObject::UnrealizeObject
- AFXWIN/CGdiObject::m_hObject
helpviewer_keywords:
- CGdiObject [MFC], CGdiObject
- CGdiObject [MFC], Attach
- CGdiObject [MFC], CreateStockObject
- CGdiObject [MFC], DeleteObject
- CGdiObject [MFC], DeleteTempMap
- CGdiObject [MFC], Detach
- CGdiObject [MFC], FromHandle
- CGdiObject [MFC], GetObject
- CGdiObject [MFC], GetObjectType
- CGdiObject [MFC], GetSafeHandle
- CGdiObject [MFC], UnrealizeObject
- CGdiObject [MFC], m_hObject
ms.assetid: 1cba3ba5-3d49-4e43-8293-209299f2f6f4
ms.openlocfilehash: 0cd7a0e0ed500ee9394b00e8906640e9f950163b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373733"
---
# <a name="cgdiobject-class"></a>Classe CGdiObject

Fornece uma classe base para vários tipos de objetos gdi (Windows graphics device interface, interface de dispositivo gráfico do Windows), como bitmaps, regiões, pincéis, canetas, paletas e fontes.

## <a name="syntax"></a>Sintaxe

```
class CGdiObject : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CGdiObject::CGdiObject](#cgdiobject)|Constrói um objeto `CGdiObject`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CGdiObject::Anexar](#attach)|Anexa um objeto Windows GDI a um `CGdiObject` objeto.|
|[CGdiObject::CreateStockObject](#createstockobject)|Recupera uma alça em uma das canetas de estoque predefinidas do Windows, pincéis ou fontes.|
|[CGdiObject::DeleteObject](#deleteobject)|Exclui o objeto GDI do `CGdiObject` Windows conectado ao objeto da memória, liberando todo o armazenamento do sistema associado ao objeto.|
|[CGdiObject::DeleteTempMap](#deletetempmap)|Exclui quaisquer `CGdiObject` objetos temporários criados por `FromHandle`.|
|[CGdiObject::Detach](#detach)|Destaca um objeto GDI do `CGdiObject` Windows de um objeto e retorna uma alça para o objeto GDI do Windows.|
|[CGdiObject::FromHandle](#fromhandle)|Retorna um ponteiro `CGdiObject` para um objeto dado uma alça a um objeto GDI do Windows.|
|[CGdiObject::GetObject](#getobject)|Preenche um buffer com dados que descrevem o objeto `CGdiObject` GDI do Windows anexado ao objeto.|
|[CGdiObject::GetObjectType](#getobjecttype)|Recupera o tipo do objeto GDI.|
|[CGdiObject::GetSafeHandle](#getsafehandle)|Retorna `m_hObject` a menos que **seja** NULO, nesse caso NULL é devolvido.|
|[CGdiObject::UnrealizeObject](#unrealizeobject)|Redefine a origem de um pincel ou redefine uma paleta lógica.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CGdiObject::operador !=](#operator_neq)|Determina se dois objetos GDI logicamente não são iguais.|
|[CGdiObject::operador ==](#operator_eq_eq)|Determina se dois objetos GDI são logicamente iguais.|
|[CGdiObject::operador HGDIOBJ](#operator_hgdiobj)|Recupera um handle para o objeto GDI do Windows conectado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CGdiObject::m_hObject](#m_hobject)|Um HANDLE contendo o HBITMAP, HPALETTE, HRGN, HBRUSH, HPEN ou HFONT conectado a este objeto.|

## <a name="remarks"></a>Comentários

Você nunca `CGdiObject` cria um diretamente. Em vez disso, você cria um objeto a `CPen` `CBrush`partir de uma de suas classes derivadas, tais como ou .

Para obter `CGdiObject`mais informações sobre , consulte [Objetos Gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CGdiObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cgdiobjectattach"></a><a name="attach"></a>CGdiObject::Anexar

Anexa um objeto Windows GDI a um `CGdiObject` objeto.

```
BOOL Attach(HGDIOBJ hObject);
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Um HANDLE para um objeto GDI do Windows (por exemplo, HPEN ou HBRUSH).

### <a name="return-value"></a>Valor retornado

Não zero se o anexo for bem sucedido; caso contrário, 0.

## <a name="cgdiobjectcgdiobject"></a><a name="cgdiobject"></a>CGdiObject::CGdiObject

Constrói um objeto `CGdiObject`.

```
CGdiObject();
```

### <a name="remarks"></a>Comentários

Você nunca `CGdiObject` cria um diretamente. Em vez disso, você cria um objeto a `CPen` `Cbrush`partir de uma de suas classes derivadas, tais como ou .

## <a name="cgdiobjectcreatestockobject"></a><a name="createstockobject"></a>CGdiObject::CreateStockObject

Recupera uma alça em uma das canetas, pincéis ou fontes do Windows Deriná-la e anexa o objeto GDI ao `CGdiObject` objeto.

```
BOOL CreateStockObject(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Uma constante especificando o tipo de objeto de estoque desejado. Consulte o parâmetro *fnObject* para [GetStockObject](/windows/win32/api/wingdi/nf-wingdi-getstockobject) no Windows SDK para obter uma descrição dos valores apropriados.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame esta função com uma das classes derivadas que corresponde ao `CPen` tipo de objeto Windows GDI, como para uma caneta de estoque.

## <a name="cgdiobjectdeleteobject"></a><a name="deleteobject"></a>CGdiObject::DeleteObject

Exclui o objeto Windows GDI conectado da memória, liberando todo o armazenamento do sistema associado ao objeto Windows GDI.

```
BOOL DeleteObject();
```

### <a name="return-value"></a>Valor retornado

Não zero se o objeto GDI foi excluído com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

O armazenamento associado `CGdiObject` ao objeto não é afetado por esta chamada. Um aplicativo não `DeleteObject` deve `CGdiObject` chamar um objeto que está atualmente selecionado em um contexto de dispositivo.

Quando um pincel padrão é excluído, o bitmap associado ao pincel não é excluído. O bitmap deve ser excluído independentemente.

## <a name="cgdiobjectdeletetempmap"></a><a name="deletetempmap"></a>CGdiObject::DeleteTempMap

Chamado automaticamente pelo `CWinApp` manipulador de `DeleteTempMap` tempo ocioso, exclui quaisquer objetos temporários `CGdiObject` criados por `FromHandle`.

```
static void PASCAL DeleteTempMap();
```

### <a name="remarks"></a>Comentários

`DeleteTempMap`destaca o objeto Windows GDI anexado `CGdiObject` a um `CGdiObject` objeto temporário antes de excluir o objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#175](../../mfc/codesnippet/cpp/cgdiobject-class_1.cpp)]

## <a name="cgdiobjectdetach"></a><a name="detach"></a>CGdiObject::Detach

Destaca um objeto GDI do `CGdiObject` Windows de um objeto e retorna uma alça para o objeto GDI do Windows.

```
HGDIOBJ Detach();
```

### <a name="return-value"></a>Valor retornado

A `HANDLE` ao objeto GDI do Windows destacado; caso contrário, NULL se nenhum objeto GDI for anexado.

## <a name="cgdiobjectfromhandle"></a><a name="fromhandle"></a>CGdiObject::FromHandle

Retorna um ponteiro `CGdiObject` para um objeto dado uma alça a um objeto GDI do Windows.

```
static CGdiObject* PASCAL FromHandle(HGDIOBJ hObject);
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
Um handle para um objeto GDI do Windows.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CGdiObject` para um que pode ser temporário ou permanente.

### <a name="remarks"></a>Comentários

Se `CGdiObject` um objeto ainda não estiver conectado ao objeto `CGdiObject` GDI do Windows, um objeto temporário será criado e anexado.

Este `CGdiObject` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, momento em que todos os objetos gráficos temporários são excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento de uma mensagem de janela.

## <a name="cgdiobjectgetobject"></a><a name="getobject"></a>CGdiObject::GetObject

Preenche um buffer com dados que definem um objeto especificado.

```
int GetObject(
    int nCount,
    LPVOID lpObject) const;
```

### <a name="parameters"></a>Parâmetros

*Ncount*<br/>
Especifica o número de bytes a serem copiados no buffer *lpObject.*

*lpObject*<br/>
Aponta para um buffer fornecido pelo usuário que deve receber as informações.

### <a name="return-value"></a>Valor retornado

O número de bytes recuperados; caso contrário 0 se ocorrer um erro.

### <a name="remarks"></a>Comentários

A função recupera uma estrutura de dados cujo tipo depende do tipo de objeto gráfico, como mostrado pela lista a seguir:

|Objeto|Tipo de buffer|
|------------|-----------------|
|`CPen`|[Logpen](/windows/win32/api/Wingdi/ns-wingdi-logpen)|
|`CBrush`|[Logbrush](/windows/win32/api/wingdi/ns-wingdi-logbrush)|
|`CFont`|[Logfont](/windows/win32/api/wingdi/ns-wingdi-logfontw)|
|`CBitmap`|[Bitmap](/windows/win32/api/wingdi/ns-wingdi-bitmap)|
|`CPalette`|WORD|
|`CRgn`|Sem suporte|

Se o objeto `CBitmap` for `GetObject` um objeto, retorne apenas as informações de largura, altura e formato de cor do bitmap. Os bits reais podem ser recuperados usando [CBitmap::GetBitmapBits](../../mfc/reference/cbitmap-class.md#getbitmapbits).

Se o objeto `CPalette` for `GetObject` um objeto, recuperará um WORD que especifica o número de entradas na paleta. A função não recupera a estrutura [LOGPALETTE](/windows/win32/api/wingdi/ns-wingdi-logpalette) que define a paleta. Um aplicativo pode obter informações sobre entradas de paleta chamando [CPalette::GetPaletteEntries](../../mfc/reference/cpalette-class.md#getpaletteentries).

## <a name="cgdiobjectgetobjecttype"></a><a name="getobjecttype"></a>CGdiObject::GetObjectType

Recupera o tipo do objeto GDI.

```
UINT GetObjectType() const;
```

### <a name="return-value"></a>Valor retornado

O tipo do objeto, se bem sucedido; caso contrário, 0. O valor pode ser um dos seguintes:

- OBJ_BITMAP Bitmap

- pincel OBJ_BRUSH

- OBJ_FONT Fonte

- paleta OBJ_PAL

- Caneta OBJ_PEN

- caneta estendida OBJ_EXTPEN

- OBJ_REGION Region

- OBJ_DC contexto do dispositivo

- OBJ_MEMDC contexto do dispositivo memory

- Metaarquivo OBJ_METAFILE

- OBJ_METADC o contexto do dispositivo Metafile

- OBJ_ENHMETAFILE metaarquivo aprimorado

- OBJ_ENHMETADC contexto do dispositivo de metaarquivos aprimorados

## <a name="cgdiobjectgetsafehandle"></a><a name="getsafehandle"></a>CGdiObject::GetSafeHandle

Retorna `m_hObject` a menos que **seja** NULO, nesse caso NULL é devolvido.

```
HGDIOBJ GetSafeHandle() const;
```

### <a name="return-value"></a>Valor retornado

Um handle para o objeto GDI do Windows conectado; caso contrário, NULL se nenhum objeto for anexado.

### <a name="remarks"></a>Comentários

Isso faz parte do paradigma geral da interface da alça e é útil quando NULL é um valor válido ou especial para uma alça.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CWnd::IsWindowEnabled](../../mfc/reference/cwnd-class.md#iswindowenabled).

## <a name="cgdiobjectm_hobject"></a><a name="m_hobject"></a>CGdiObject::m_hObject

Um HANDLE contendo o HBITMAP, HRGN, HBRUSH, HPEN, HPALETTE ou HFONT conectado a este objeto.

```
HGDIOBJ m_hObject;
```

## <a name="cgdiobjectoperator-"></a><a name="operator_neq"></a>CGdiObject::operador !=

Determina se dois objetos GDI logicamente não são iguais.

```
BOOL operator!=(const CGdiObject& obj) const;
```

### <a name="parameters"></a>Parâmetros

*obj*<br/>
Um ponteiro para `CGdiObject`um existente.

### <a name="remarks"></a>Comentários

Determina se um objeto GDI no lado esquerdo não é igual a um objeto GDI no lado direito.

## <a name="cgdiobjectoperator-"></a><a name="operator_eq_eq"></a>CGdiObject::operador ==

Determina se dois objetos GDI são logicamente iguais.

```
BOOL operator==(const CGdiObject& obj) const;
```

### <a name="parameters"></a>Parâmetros

*obj*<br/>
Uma referência a `CGdiObject`um existente.

### <a name="remarks"></a>Comentários

Determina se um objeto GDI no lado esquerdo é igual a um objeto GDI no lado direito.

## <a name="cgdiobjectoperator-hgdiobj"></a><a name="operator_hgdiobj"></a>CGdiObject::operador HGDIOBJ

Recupera um handle para o objeto GDI do Windows conectado; caso contrário, NULL se nenhum objeto for anexado.

```
operator HGDIOBJ() const;
```

## <a name="cgdiobjectunrealizeobject"></a><a name="unrealizeobject"></a>CGdiObject::UnrealizeObject

Redefine a origem de um pincel ou redefine uma paleta lógica.

```
BOOL UnrealizeObject();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Embora `UnrealizeObject` seja uma função `CGdiObject` membro da classe, ela `CBrush` `CPalette` deve ser invocada apenas em ou objetos.

Para `CBrush` objetos, `UnrealizeObject` o sistema direciona o sistema para redefinir a origem da escova dada na próxima vez que for selecionado em um contexto do dispositivo. Se o objeto `CPalette` é `UnrealizeObject` um objeto, direciona o sistema para realizar a paleta como se não tivesse sido realizada anteriormente. Na próxima vez que o aplicativo chamar a função [CDC::RealizePalette](../../mfc/reference/cdc-class.md#realizepalette) para a paleta especificada, o sistema remapeia completamente a paleta lógica para a paleta do sistema.

A `UnrealizeObject` função não deve ser usada com objetos de estoque. A `UnrealizeObject` função deve ser chamada sempre que uma nova origem do pincel for definida (por meio da função [CDC::SetBrushOrg).](../../mfc/reference/cdc-class.md#setbrushorg) A `UnrealizeObject` função não deve ser chamada para o pincel selecionado no momento ou a paleta selecionada de qualquer contexto de exibição.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CBitmap](../../mfc/reference/cbitmap-class.md)<br/>
[Classe CBrush](../../mfc/reference/cbrush-class.md)<br/>
[Classe Cfont](../../mfc/reference/cfont-class.md)<br/>
[Classe CPalette](../../mfc/reference/cpalette-class.md)<br/>
[Classe CPen](../../mfc/reference/cpen-class.md)<br/>
[Classe CRgn](../../mfc/reference/crgn-class.md)
