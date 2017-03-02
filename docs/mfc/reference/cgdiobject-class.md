---
title: Classe CGdiObject | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CGdiObject
dev_langs:
- C++
helpviewer_keywords:
- brushes, base class for
- fonts, base class for
- regions, base class for
- pens, base class for
- palettes, base class for
- CGdiObject class
- GDI objects, base class for
ms.assetid: 1cba3ba5-3d49-4e43-8293-209299f2f6f4
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 7fb0cd49c6a20263a5cae305b7f08f2733033ff2
ms.lasthandoff: 02/25/2017

---
# <a name="cgdiobject-class"></a>Classe CGdiObject
Fornece uma classe base para vários tipos de gráficos do Windows objetos GDI (interface) do dispositivo como bitmaps, regiões, pincéis, canetas, paletas e fontes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CGdiObject : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGdiObject::CGdiObject](#cgdiobject)|Constrói um objeto `CGdiObject`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGdiObject::Attach](#attach)|Anexa um objeto GDI do Windows para uma `CGdiObject` objeto.|  
|[CGdiObject::CreateStockObject](#createstockobject)|Recupera um identificador para uma das fontes, pincéis ou canetas ações predefinidas do Windows.|  
|[CGdiObject::DeleteObject](#deleteobject)|Exclui o objeto GDI do Windows associado a `CGdiObject` objeto da memória, liberando todo o armazenamento de sistema associado ao objeto.|  
|[CGdiObject::DeleteTempMap](#deletetempmap)|Exclui qualquer temporário `CGdiObject` objetos criados pelo `FromHandle`.|  
|[CGdiObject::Detach](#detach)|Desanexa um objeto GDI do Windows de um `CGdiObject` de objeto e retorna um identificador para o objeto GDI do Windows.|  
|[CGdiObject::FromHandle](#fromhandle)|Retorna um ponteiro para um `CGdiObject` objeto recebe um identificador para um objeto GDI do Windows.|  
|[CGdiObject::GetObject](#getobject)|Preencher um buffer com dados que descrevem o objeto GDI do Windows conectado ao `CGdiObject` objeto.|  
|[CGdiObject::GetObjectType](#getobjecttype)|Recupera o tipo do objeto GDI.|  
|[CGdiObject::GetSafeHandle](#getsafehandle)|Retorna `m_hObject` , a menos que `this` é `NULL`, caso em que `NULL` é retornado.|  
|[CGdiObject::UnrealizeObject](#unrealizeobject)|Redefine a origem de um pincel ou redefine uma paleta lógica.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGdiObject::operator! =](#operator_neq)|Determina se dois objetos GDI logicamente não são iguais.|  
|[CGdiObject::operator = =](#operator_eq_eq)|Determina se dois objetos GDI são logicamente iguais.|  
|[CGdiObject::operator HGDIOBJ](#operator_hgdiobj)|Recupera um `HANDLE` ao objeto Windows GDI anexado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGdiObject::m_hObject](#m_hobject)|A `HANDLE` que contém o `HBITMAP`, `HPALETTE`, `HRGN`, `HBRUSH`, `HPEN`, ou `HFONT` anexado a este objeto.|  
  
## <a name="remarks"></a>Comentários  
 Você nunca cria um `CGdiObject` diretamente. Em vez disso, crie um objeto de uma de suas classes derivadas, como `CPen` ou `CBrush`.  
  
 Para obter mais informações sobre `CGdiObject`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CGdiObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-nameattacha--cgdiobjectattach"></a><a name="attach"></a>CGdiObject::Attach  
 Anexa um objeto GDI do Windows para uma `CGdiObject` objeto.  
  
```  
BOOL Attach(HGDIOBJ hObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 A `HANDLE` para um objeto GDI do Windows (por exemplo, `HPEN` ou `HBRUSH`).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o anexo for bem-sucedida; Caso contrário, 0.  
  
##  <a name="a-namecgdiobjecta--cgdiobjectcgdiobject"></a><a name="cgdiobject"></a>CGdiObject::CGdiObject  
 Constrói um objeto `CGdiObject`.  
  
```  
CGdiObject();
```  
  
### <a name="remarks"></a>Comentários  
 Você nunca cria um `CGdiObject` diretamente. Em vez disso, crie um objeto de uma de suas classes derivadas, como `CPen` ou **Cbrush**.  
  
##  <a name="a-namecreatestockobjecta--cgdiobjectcreatestockobject"></a><a name="createstockobject"></a>CGdiObject::CreateStockObject  
 Recupera um identificador para uma das fontes, pincéis ou predefinidas canetas Windows GDI estoque e anexa o objeto GDI para o `CGdiObject` objeto.  
  
```  
BOOL CreateStockObject(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Uma constante especificando o tipo de objeto de estoque desejado. Consulte o parâmetro *fnObject* para [GetStockObject](http://msdn.microsoft.com/library/windows/desktop/dd144925) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma descrição dos valores apropriados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamada para essa função com um dos derivados de classes que corresponde ao tipo de objeto GDI do Windows, como `CPen` de uma caneta de estoque.  
  
##  <a name="a-namedeleteobjecta--cgdiobjectdeleteobject"></a><a name="deleteobject"></a>CGdiObject::DeleteObject  
 Exclui o objeto de Windows GDI anexado da memória ao liberar todo o armazenamento de sistema associado ao objeto GDI do Windows.  
  
```  
BOOL DeleteObject();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto GDI foi excluído com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O armazenamento associado a `CGdiObject` objeto não é afetado por essa chamada. Um aplicativo não deve chamar `DeleteObject` em uma `CGdiObject` objeto atualmente selecionado em um contexto de dispositivo.  
  
 Quando um pincel de padrão é excluído, o bitmap associado com o pincel não é excluído. O bitmap deve ser excluído independentemente.  
  
##  <a name="a-namedeletetempmapa--cgdiobjectdeletetempmap"></a><a name="deletetempmap"></a>CGdiObject::DeleteTempMap  
 Chamado automaticamente pelo `CWinApp` manipulador de tempo ocioso, `DeleteTempMap` exclui qualquer temporário `CGdiObject` objetos criados pelo `FromHandle`.  
  
```  
static void PASCAL DeleteTempMap();
```  
  
### <a name="remarks"></a>Comentários  
 `DeleteTempMap`desanexa o objeto Windows GDI anexado a um temporário `CGdiObject` objeto antes de excluir o `CGdiObject` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#175;](../../mfc/codesnippet/cpp/cgdiobject-class_1.cpp)]  
  
##  <a name="a-namedetacha--cgdiobjectdetach"></a><a name="detach"></a>CGdiObject::Detach  
 Desanexa um objeto GDI do Windows de um `CGdiObject` de objeto e retorna um identificador para o objeto GDI do Windows.  
  
```  
HGDIOBJ Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A `HANDLE` para Windows GDI objeto desanexado; caso contrário **nulo** se nenhum objeto GDI é anexado.  
  
##  <a name="a-namefromhandlea--cgdiobjectfromhandle"></a><a name="fromhandle"></a>CGdiObject::FromHandle  
 Retorna um ponteiro para um `CGdiObject` objeto recebe um identificador para um objeto GDI do Windows.  
  
```  
static CGdiObject* PASCAL FromHandle(HGDIOBJ hObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 Um `HANDLE` para um objeto GDI do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CGdiObject` que pode ser temporário ou permanente.  
  
### <a name="remarks"></a>Comentários  
 Se um `CGdiObject` objeto já não está anexado ao objeto GDI do Windows, um temporário `CGdiObject` objeto é criado e anexado.  
  
 Esse temporário `CGdiObject` objeto só é válido até a próxima vez que o aplicativo tem tempo ocioso em seu loop de evento, em que todos os objetos gráficos temporários são excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento da mensagem de uma janela.  
  
##  <a name="a-namegetobjecta--cgdiobjectgetobject"></a><a name="getobject"></a>CGdiObject::GetObject  
 Preenche um buffer com dados que define um objeto especificado.  
  
```  
int GetObject(
    int nCount,  
    LPVOID lpObject) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCount`  
 Especifica o número de bytes a serem copiados para o `lpObject` buffer.  
  
 `lpObject`  
 Aponta para um buffer fornecido pelo usuário que receberá as informações.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes é recuperado. Caso contrário, 0 se um erro ocorrerá.  
  
### <a name="remarks"></a>Comentários  
 A função recupera uma estrutura de dados cujo tipo depende do tipo de objeto gráfico, como mostrado na seguinte lista:  
  
|Objeto|Tipo de buffer|  
|------------|-----------------|  
|`CPen`|[LOGPEN](../../mfc/reference/logpen-structure.md)|  
|`CBrush`|[LOGBRUSH](../../mfc/reference/logbrush-structure.md)|  
|`CFont`|[LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037)|  
|`CBitmap`|[BITMAP](../../mfc/reference/bitmap-structure.md)|  
|`CPalette`|**WORD**|  
|`CRgn`|Sem suporte|  
  
 Se o objeto for uma `CBitmap` objeto, `GetObject` retorna apenas a largura, altura e informações de formato de cor do bitmap. Os bits reais podem ser recuperados usando [CBitmap::GetBitmapBits](../../mfc/reference/cbitmap-class.md#getbitmapbits).  
  
 Se o objeto for uma `CPalette` objeto, `GetObject` recupera um **WORD** que especifica o número de entradas na paleta. A função não recuperar o [LOGPALETTE](http://msdn.microsoft.com/library/windows/desktop/dd145040) estrutura que define a paleta. Um aplicativo pode obter informações sobre entradas de paleta chamando [CPalette::GetPaletteEntries](../../mfc/reference/cpalette-class.md#getpaletteentries).  
  
##  <a name="a-namegetobjecttypea--cgdiobjectgetobjecttype"></a><a name="getobjecttype"></a>CGdiObject::GetObjectType  
 Recupera o tipo do objeto GDI.  
  
```  
UINT GetObjectType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo do objeto, se for bem-sucedido; Caso contrário, 0. O valor pode ser um dos seguintes:  
  
- **OBJ_BITMAP** Bitmap  
  
- **OBJ_BRUSH** pincel  
  
- **OBJ_FONT** fonte  
  
- **OBJ_PAL** paleta  
  
- **OBJ_PEN** caneta  
  
- **OBJ_EXTPEN** estendida caneta  
  
- **OBJ_REGION** região  
  
- **OBJ_DC** o contexto de dispositivo  
  
- **OBJ_MEMDC** contexto de dispositivo de memória  
  
- **OBJ_METAFILE** metarquivo  
  
- **OBJ_METADC** metarquivo contexto de dispositivo  
  
- **OBJ_ENHMETAFILE** metarquivo avançado  
  
- **OBJ_ENHMETADC** o contexto de dispositivo metarquivo avançado  
  
##  <a name="a-namegetsafehandlea--cgdiobjectgetsafehandle"></a><a name="getsafehandle"></a>CGdiObject::GetSafeHandle  
 Retorna `m_hObject` , a menos que **isso** é **nulo**, caso em que **nulo** é retornado.  
  
```  
HGDIOBJ GetSafeHandle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A `HANDLE` ao objeto Windows GDI anexado; caso contrário, **nulo** se nenhum objeto for anexado.  
  
### <a name="remarks"></a>Comentários  
 Isso faz parte do paradigma de interface identificador geral e é útil quando **nulo** é um valor válido ou especial para um identificador.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::IsWindowEnabled](../../mfc/reference/cwnd-class.md#iswindowenabled).  
  
##  <a name="a-namemhobjecta--cgdiobjectmhobject"></a><a name="m_hobject"></a>CGdiObject::m_hObject  
 A `HANDLE` que contém o `HBITMAP`, **HRGN**, `HBRUSH`, `HPEN`, `HPALETTE`, ou **HFONT** anexado a este objeto.  
  
```  
HGDIOBJ m_hObject;  
```  
  
##  <a name="a-nameoperatorneqa--cgdiobjectoperator-"></a><a name="operator_neq"></a>CGdiObject::operator! =  
 Determina se dois objetos GDI logicamente não são iguais.  
  
```  
BOOL operator!=(const CGdiObject& obj) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `obj`  
 Um ponteiro para um existente `CGdiObject`.  
  
### <a name="remarks"></a>Comentários  
 Determina se um objeto GDI no lado esquerdo não é igual ao objeto GDI no lado direito.  
  
##  <a name="a-nameoperatoreqeqa--cgdiobjectoperator-"></a><a name="operator_eq_eq"></a>CGdiObject::operator = =  
 Determina se dois objetos GDI são logicamente iguais.  
  
```  
BOOL operator==(const CGdiObject& obj) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `obj`  
 Uma referência a um existente `CGdiObject`.  
  
### <a name="remarks"></a>Comentários  
 Determina se um objeto GDI no lado esquerdo for igual ao objeto GDI no lado direito.  
  
##  <a name="a-nameoperatorhgdiobja--cgdiobjectoperator-hgdiobj"></a><a name="operator_hgdiobj"></a>CGdiObject::operator HGDIOBJ  
 Recupera um `HANDLE` ao objeto Windows GDI anexado; caso contrário, **nulo** se nenhum objeto for anexado.  
  
```  
operator HGDIOBJ() const;  
```  
  
##  <a name="a-nameunrealizeobjecta--cgdiobjectunrealizeobject"></a><a name="unrealizeobject"></a>CGdiObject::UnrealizeObject  
 Redefine a origem de um pincel ou redefine uma paleta lógica.  
  
```  
BOOL UnrealizeObject();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Enquanto `UnrealizeObject` é uma função de membro de `CGdiObject` classe, ele deve ser chamado somente em `CBrush` ou `CPalette` objetos.  
  
 Para `CBrush` objetos, `UnrealizeObject` direciona o sistema para redefinir a origem do pincel determinado na próxima vez que ele é selecionado em um contexto de dispositivo. Se o objeto for uma `CPalette` objeto `UnrealizeObject` direciona o sistema perceber a paleta como se ele tivesse não anteriormente foi concretizado. Na próxima vez que o aplicativo chama o [CDC::RealizePalette](../../mfc/reference/cdc-class.md#realizepalette) função para a paleta especificada, o sistema completamente remapeia paleta lógica na paleta do sistema.  
  
 O `UnrealizeObject` função não deve ser usada com objetos de estoque. O `UnrealizeObject` função deve ser chamada sempre que uma nova origem de pincel é definida (por meio do [CDC::SetBrushOrg](../../mfc/reference/cdc-class.md#setbrushorg) função). O `UnrealizeObject` função não deve ser chamada para o pincel selecionado no momento ou paleta selecionada no momento de qualquer contexto de exibição.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CBitmap](../../mfc/reference/cbitmap-class.md)   
 [Classe CBrush](../../mfc/reference/cbrush-class.md)   
 [Classe CFont](../../mfc/reference/cfont-class.md)   
 [Classe CPalette](../../mfc/reference/cpalette-class.md)   
 [Classe CPen](../../mfc/reference/cpen-class.md)   
 [Classe CRgn](../../mfc/reference/crgn-class.md)

