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
ms.openlocfilehash: 759b25a8f77bb4e6b372431b637b4a97aca8e149
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212404"
---
# <a name="cgdiobject-class"></a>Classe CGdiObject

Fornece uma classe base para vários tipos de objetos da interface de dispositivo gráfico do Windows (GDI), como bitmaps, regiões, pincéis, canetas, paletas e fontes.

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
|[CGdiObject:: Attach](#attach)|Anexa um objeto GDI do Windows a um `CGdiObject` objeto.|
|[CGdiObject:: CreateStockObject](#createstockobject)|Recupera um identificador para uma das canetas, pincéis ou fontes de ações predefinidas do Windows.|
|[CGdiObject::D eleteObject](#deleteobject)|Exclui o objeto GDI do Windows anexado ao `CGdiObject` objeto da memória, liberando todo o armazenamento do sistema associado ao objeto.|
|[CGdiObject::D eleteTempMap](#deletetempmap)|Exclui todos os `CGdiObject` objetos temporários criados pelo `FromHandle` .|
|[CGdiObject::D Etach](#detach)|Desanexa um objeto GDI do Windows de um `CGdiObject` objeto e retorna um identificador para o objeto GDI do Windows.|
|[CGdiObject:: FromHandle](#fromhandle)|Retorna um ponteiro para um `CGdiObject` objeto dado um identificador a um objeto GDI do Windows.|
|[CGdiObject:: GetObject](#getobject)|Preenche um buffer com dados que descreve o objeto GDI do Windows anexado ao `CGdiObject` objeto.|
|[CGdiObject:: GetObjectType](#getobjecttype)|Recupera o tipo do objeto GDI.|
|[CGdiObject:: GetSafeHandle](#getsafehandle)|Retorna `m_hObject` a menos que **`this`** seja NULL; nesse caso, NULL é retornado.|
|[CGdiObject:: unpercebeuobject](#unrealizeobject)|Redefine a origem de um pincel ou redefine uma paleta lógica.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CGdiObject:: Operator! =](#operator_neq)|Determina se dois objetos GDI são logicamente diferentes.|
|[CGdiObject:: Operator = =](#operator_eq_eq)|Determina se dois objetos GDI são logicamente iguais.|
|[Operador CGdiObject:: Operator HGDIOBJ](#operator_hgdiobj)|Recupera um identificador para o objeto GDI do Windows anexado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CGdiObject:: m_hObject](#m_hobject)|Um identificador que contém HBITMAP, HPALETTE, HRGN, HBRUSH, HPEN ou HFONT anexado a esse objeto.|

## <a name="remarks"></a>Comentários

Você nunca cria um `CGdiObject` diretamente. Em vez disso, você cria um objeto de uma de suas classes derivadas, como `CPen` ou `CBrush` .

Para obter mais informações sobre o `CGdiObject` , consulte [objetos gráficos](../../mfc/graphic-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CGdiObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="cgdiobjectattach"></a><a name="attach"></a>CGdiObject:: Attach

Anexa um objeto GDI do Windows a um `CGdiObject` objeto.

```
BOOL Attach(HGDIOBJ hObject);
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Um identificador para um objeto GDI do Windows (por exemplo, HPEN ou HBRUSH).

### <a name="return-value"></a>Valor retornado

Diferente de zero se o anexo for bem-sucedido; caso contrário, 0.

## <a name="cgdiobjectcgdiobject"></a><a name="cgdiobject"></a>CGdiObject::CGdiObject

Constrói um objeto `CGdiObject`.

```
CGdiObject();
```

### <a name="remarks"></a>Comentários

Você nunca cria um `CGdiObject` diretamente. Em vez disso, você cria um objeto de uma de suas classes derivadas, como `CPen` ou `Cbrush` .

## <a name="cgdiobjectcreatestockobject"></a><a name="createstockobject"></a>CGdiObject:: CreateStockObject

Recupera um identificador para uma das ações, pincéis ou fontes do Windows GDI predefinidos e anexa o objeto GDI ao `CGdiObject` objeto.

```
BOOL CreateStockObject(int nIndex);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Uma constante que especifica o tipo de objeto de estoque desejado. Consulte o parâmetro *fnObject* para [GetStockObject](/windows/win32/api/wingdi/nf-wingdi-getstockobject) no SDK do Windows para obter uma descrição dos valores apropriados.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função com uma das classes derivadas que corresponde ao tipo de objeto GDI do Windows, como `CPen` para uma caneta de ações.

## <a name="cgdiobjectdeleteobject"></a><a name="deleteobject"></a>CGdiObject::D eleteObject

Exclui o objeto GDI do Windows anexado da memória, liberando todo o armazenamento do sistema associado ao objeto GDI do Windows.

```
BOOL DeleteObject();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto GDI tiver sido excluído com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

O armazenamento associado ao `CGdiObject` objeto não é afetado por essa chamada. Um aplicativo não deve chamar `DeleteObject` em um `CGdiObject` objeto que está selecionado no momento em um contexto de dispositivo.

Quando um pincel de padrão é excluído, o bitmap associado ao pincel não é excluído. O bitmap deve ser excluído independentemente.

## <a name="cgdiobjectdeletetempmap"></a><a name="deletetempmap"></a>CGdiObject::D eleteTempMap

Chamado automaticamente pelo `CWinApp` manipulador de tempo ocioso, `DeleteTempMap` exclui todos os objetos temporários `CGdiObject` criados pelo `FromHandle` .

```
static void PASCAL DeleteTempMap();
```

### <a name="remarks"></a>Comentários

`DeleteTempMap`Desanexa o objeto GDI do Windows anexado a um `CGdiObject` objeto temporário antes de excluir o `CGdiObject` objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#175](../../mfc/codesnippet/cpp/cgdiobject-class_1.cpp)]

## <a name="cgdiobjectdetach"></a><a name="detach"></a>CGdiObject::D Etach

Desanexa um objeto GDI do Windows de um `CGdiObject` objeto e retorna um identificador para o objeto GDI do Windows.

```
HGDIOBJ Detach();
```

### <a name="return-value"></a>Valor retornado

Um `HANDLE` para o objeto GDI do Windows desanexado; caso contrário, NULL se nenhum objeto GDI estiver anexado.

## <a name="cgdiobjectfromhandle"></a><a name="fromhandle"></a>CGdiObject:: FromHandle

Retorna um ponteiro para um `CGdiObject` objeto dado um identificador a um objeto GDI do Windows.

```
static CGdiObject* PASCAL FromHandle(HGDIOBJ hObject);
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
Um identificador para um objeto GDI do Windows.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um `CGdiObject` que pode ser temporário ou permanente.

### <a name="remarks"></a>Comentários

Se um `CGdiObject` objeto ainda não estiver anexado ao objeto GDI do Windows, um `CGdiObject` objeto temporário será criado e anexado.

Esse `CGdiObject` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos, quando todos os objetos gráficos temporários forem excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento de uma mensagem de janela.

## <a name="cgdiobjectgetobject"></a><a name="getobject"></a>CGdiObject:: GetObject

Preenche um buffer com dados que define um objeto especificado.

```
int GetObject(
    int nCount,
    LPVOID lpObject) const;
```

### <a name="parameters"></a>parâmetros

*nCount*<br/>
Especifica o número de bytes a serem copiados no buffer *lpObject* .

*lpObject*<br/>
Aponta para um buffer fornecido pelo usuário que deve receber as informações.

### <a name="return-value"></a>Valor retornado

O número de bytes recuperados; caso contrário, 0 se ocorrer um erro.

### <a name="remarks"></a>Comentários

A função recupera uma estrutura de dados cujo tipo depende do tipo de objeto gráfico, conforme mostrado na lista a seguir:

|Objeto|Tipo de buffer|
|------------|-----------------|
|`CPen`|[LOGPEN](/windows/win32/api/Wingdi/ns-wingdi-logpen)|
|`CBrush`|[LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush)|
|`CFont`|[LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw)|
|`CBitmap`|[BITMAP](/windows/win32/api/wingdi/ns-wingdi-bitmap)|
|`CPalette`|WORD|
|`CRgn`|Sem suporte|

Se o objeto for um `CBitmap` objeto, `GetObject` retornará apenas as informações de largura, altura e formato de cor do bitmap. Os bits reais podem ser recuperados usando [CBitmap:: GetBitmapBits](../../mfc/reference/cbitmap-class.md#getbitmapbits).

Se o objeto for um `CPalette` objeto, o `GetObject` recuperará uma palavra que especifica o número de entradas na paleta. A função não recupera a estrutura [LOGPALETTE](/windows/win32/api/wingdi/ns-wingdi-logpalette) que define a paleta. Um aplicativo pode obter informações sobre entradas da paleta chamando [CPalette:: GetPaletteEntries](../../mfc/reference/cpalette-class.md#getpaletteentries).

## <a name="cgdiobjectgetobjecttype"></a><a name="getobjecttype"></a>CGdiObject:: GetObjectType

Recupera o tipo do objeto GDI.

```
UINT GetObjectType() const;
```

### <a name="return-value"></a>Valor retornado

O tipo do objeto, se for bem-sucedido; caso contrário, 0. O valor pode ser um dos seguintes:

- OBJ_BITMAP bitmap

- Pincel de OBJ_BRUSH

- Fonte OBJ_FONT

- Paleta de OBJ_PAL

- Caneta OBJ_PEN

- OBJ_EXTPEN caneta estendida

- Região de OBJ_REGION

- OBJ_DC contexto do dispositivo

- Contexto de dispositivo de memória OBJ_MEMDC

- OBJ_METAFILE metarquivo

- Contexto de dispositivo de OBJ_METADC Metafile

- OBJ_ENHMETAFILE metarquivo avançado

- OBJ_ENHMETADC contexto de dispositivo de metarquivo avançado

## <a name="cgdiobjectgetsafehandle"></a><a name="getsafehandle"></a>CGdiObject:: GetSafeHandle

Retorna `m_hObject` a menos que **`this`** seja NULL; nesse caso, NULL é retornado.

```
HGDIOBJ GetSafeHandle() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para o objeto GDI do Windows anexado; caso contrário, NULL se nenhum objeto estiver anexado.

### <a name="remarks"></a>Comentários

Isso faz parte do paradigma de interface de identificador geral e é útil quando NULL é um valor válido ou especial para um identificador.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CWnd:: IsWindowEnabled](../../mfc/reference/cwnd-class.md#iswindowenabled).

## <a name="cgdiobjectm_hobject"></a><a name="m_hobject"></a>CGdiObject:: m_hObject

Um identificador que contém HBITMAP, HRGN, HBRUSH, HPEN, HPALETTE ou HFONT anexado a esse objeto.

```
HGDIOBJ m_hObject;
```

## <a name="cgdiobjectoperator-"></a><a name="operator_neq"></a>CGdiObject:: Operator! =

Determina se dois objetos GDI são logicamente diferentes.

```
BOOL operator!=(const CGdiObject& obj) const;
```

### <a name="parameters"></a>parâmetros

*obj*<br/>
Um ponteiro para um existente `CGdiObject` .

### <a name="remarks"></a>Comentários

Determina se um objeto GDI no lado esquerdo não é igual a um objeto GDI no lado direito.

## <a name="cgdiobjectoperator-"></a><a name="operator_eq_eq"></a>CGdiObject:: Operator = =

Determina se dois objetos GDI são logicamente iguais.

```
BOOL operator==(const CGdiObject& obj) const;
```

### <a name="parameters"></a>parâmetros

*obj*<br/>
Uma referência a um existente `CGdiObject` .

### <a name="remarks"></a>Comentários

Determina se um objeto GDI no lado esquerdo é igual a um objeto GDI no lado direito.

## <a name="cgdiobjectoperator-hgdiobj"></a><a name="operator_hgdiobj"></a>Operador CGdiObject:: Operator HGDIOBJ

Recupera um identificador para o objeto GDI do Windows anexado; caso contrário, NULL se nenhum objeto estiver anexado.

```
operator HGDIOBJ() const;
```

## <a name="cgdiobjectunrealizeobject"></a><a name="unrealizeobject"></a>CGdiObject:: unpercebeuobject

Redefine a origem de um pincel ou redefine uma paleta lógica.

```
BOOL UnrealizeObject();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Embora `UnrealizeObject` seja uma função membro da `CGdiObject` classe, ela deve ser invocada somente em `CBrush` `CPalette` objetos ou.

Para `CBrush` objetos, o `UnrealizeObject` direciona o sistema para redefinir a origem do pincel fornecido na próxima vez que for selecionado em um contexto de dispositivo. Se o objeto for um `CPalette` objeto, o `UnrealizeObject` instruirá o sistema a obter a paleta como se ela não tivesse sido realizada anteriormente. Na próxima vez que o aplicativo chamar a função [CDC:: RealizePalette](../../mfc/reference/cdc-class.md#realizepalette) para a paleta especificada, o sistema remapeará completamente a paleta lógica para a paleta do sistema.

A `UnrealizeObject` função não deve ser usada com objetos stock. A `UnrealizeObject` função deve ser chamada sempre que uma nova origem de pincel for definida (por meio da função [CDC:: SetBrushOrg](../../mfc/reference/cdc-class.md#setbrushorg) ). A `UnrealizeObject` função não deve ser chamada para o pincel selecionado atualmente ou para a paleta selecionada no momento de qualquer contexto de exibição.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CBitmap](../../mfc/reference/cbitmap-class.md)<br/>
[Classe CBrush](../../mfc/reference/cbrush-class.md)<br/>
[Classe CFont](../../mfc/reference/cfont-class.md)<br/>
[Classe CPalette](../../mfc/reference/cpalette-class.md)<br/>
[Classe CPen](../../mfc/reference/cpen-class.md)<br/>
[Classe CRgn](../../mfc/reference/crgn-class.md)
