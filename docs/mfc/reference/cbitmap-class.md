---
title: Classe CBitmap | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CBitmap
dev_langs:
- C++
helpviewer_keywords:
- drawing, tools
- CBitmap class
- GDI bitmap
ms.assetid: 3980616a-c59d-495a-86e6-62bd3889c84c
caps.latest.revision: 22
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
ms.openlocfilehash: ccfe592bbbae8c0eff22baa6e1baac56754ef6fc
ms.lasthandoff: 02/25/2017

---
# <a name="cbitmap-class"></a>Classe CBitmap
Encapsula um bitmap GDI (interface) de dispositivo de gráficos de Windows e fornece funções de membro para manipular o bitmap.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CBitmap : public CGdiObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBitmap::CBitmap](#cbitmap)|Constrói um objeto `CBitmap`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBitmap::CreateBitmap](#createbitmap)|Inicializa o objeto com um bitmap de memória do dispositivo dependente que tem uma largura especificada, a altura e o padrão de bits.|  
|[CBitmap::CreateBitmapIndirect](#createbitmapindirect)|Inicializa o objeto com um bitmap a largura, altura e padrão de bit (se um for especificado) fornecido uma **BITMAP** estrutura.|  
|[CBitmap::CreateCompatibleBitmap](#createcompatiblebitmap)|Inicializa o objeto com um bitmap para que seja compatível com um dispositivo especificado.|  
|[CBitmap::CreateDiscardableBitmap](#creatediscardablebitmap)|Inicializa o objeto com um bitmap descartável que seja compatível com um dispositivo especificado.|  
|[CBitmap::FromHandle](#fromhandle)|Retorna um ponteiro para um `CBitmap` objeto quando recebe um identificador para um Windows `HBITMAP` bitmap.|  
|[CBitmap::GetBitmap](#getbitmap)|Preenche um **BITMAP** estrutura com informações sobre o bitmap.|  
|[CBitmap::GetBitmapBits](#getbitmapbits)|Copia os bits do bitmap especificado no buffer especificado.|  
|[CBitmap::GetBitmapDimension](#getbitmapdimension)|Retorna a largura e altura do bitmap. A altura e largura são considerados tiver sido definido anteriormente o [SetBitmapDimension](#setbitmapdimension) função de membro.|  
|[CBitmap::LoadBitmap](#loadbitmap)|Inicializa o objeto carregar um recurso de bitmap nomeado do arquivo executável do aplicativo e anexando o bitmap para o objeto.|  
|[CBitmap::LoadMappedBitmap](#loadmappedbitmap)|Carrega um bitmap e mapeia as cores para as cores do sistema atual.|  
|[CBitmap::LoadOEMBitmap](#loadoembitmap)|Inicializa o objeto ao carregar um bitmap do Windows predefinido e anexando o bitmap para o objeto.|  
|[CBitmap::SetBitmapBits](#setbitmapbits)|Define os bits de um bitmap com os valores de bit especificado.|  
|[CBitmap::SetBitmapDimension](#setbitmapdimension)|Atribui uma largura e altura de um bitmap em unidades de 0,1 milímetros.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBitmap::operator HBITMAP](#operator_hbitmap)|Retorna o identificador anexado ao `CBitmap` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para usar um `CBitmap` do objeto, construir o objeto, anexar um identificador de bitmap com uma das funções de membro de inicialização e chamar funções de membro do objeto.  
  
 Para obter mais informações sobre como usar objetos gráficos como `CBitmap`, consulte [gráfico objetos](../../mfc/graphic-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CBitmap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-namecbitmapa--cbitmapcbitmap"></a><a name="cbitmap"></a>CBitmap::CBitmap  
 Constrói um objeto `CBitmap`.  
  
```  
CBitmap();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto resultante deve ser inicializado com uma das funções de membro de inicialização.  
  
##  <a name="a-namecreatebitmapa--cbitmapcreatebitmap"></a><a name="createbitmap"></a>CBitmap::CreateBitmap  
 Inicializa um bitmap dependente de dispositivo de memória com o padrão de bits, altura e largura especificada.  
  
```  
BOOL CreateBitmap(
    int nWidth,  
    int nHeight,  
    UINT nPlanes,  
    UINT nBitcount,  
    const void* lpBits);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nWidth`  
 Especifica a largura (em pixels) do bitmap.  
  
 `nHeight`  
 Especifica a altura (em pixels) do bitmap.  
  
 `nPlanes`  
 Especifica o número de planos de cores no bitmap.  
  
 `nBitcount`  
 Especifica o número de bits de cores por pixel de vídeo.  
  
 `lpBits`  
 Aponta para uma matriz de bytes que contém os valores de bit de bitmap inicial. Se for **nulo**, o novo bitmap é deixado não inicializado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para um bitmap de cor, tanto o `nPlanes` ou `nBitcount` parâmetro deve ser definido como 1. Se ambos os parâmetros são definidos como 1, `CreateBitmap` cria um bitmap monocromático.  
  
 Embora um bitmap não pode ser selecionado diretamente para um dispositivo de vídeo, ele pode ser selecionado como o bitmap atual de um contexto de dispositivo"memória" usando [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) e copiado para qualquer contexto de dispositivo compatível com o uso de [CDC::BitBlt](../../mfc/reference/cdc-class.md#bitblt) função.  
  
 Quando você terminar com a `CBitmap` objeto criado pelo `CreateBitmap` funcionar, primeiro selecione o bitmap fora do contexto de dispositivo, excluir o `CBitmap` objeto.  
  
 Para obter mais informações, consulte a descrição do **bmBits** campo o **BITMAP** estrutura. O [BITMAP](../../mfc/reference/bitmap-structure.md) estrutura é descrita no [CBitmap::CreateBitmapIndirect](#createbitmapindirect) função de membro.  
  
##  <a name="a-namecreatebitmapindirecta--cbitmapcreatebitmapindirect"></a><a name="createbitmapindirect"></a>CBitmap::CreateBitmapIndirect  
 Inicializa um bitmap que possui a largura, altura e padrão de bit (se um for especificado) fornecido na estrutura apontada por `lpBitmap`.  
  
```  
BOOL CreateBitmapIndirect(LPBITMAP lpBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpBitmap`  
 Aponta para um [BITMAP](../../mfc/reference/bitmap-structure.md) estrutura que contém informações sobre o bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Embora um bitmap não pode ser selecionado diretamente para um dispositivo de vídeo, ele pode ser selecionado como o bitmap atual de um contexto de dispositivo de memória usando [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) e copiado para qualquer contexto de dispositivo compatível com o uso de [CDC::BitBlt](../../mfc/reference/cdc-class.md#bitblt) ou [CDC::StretchBlt](../../mfc/reference/cdc-class.md#stretchblt) função. (O [CDC::PatBlt](../../mfc/reference/cdc-class.md#patblt) função pode copiar o bitmap do pincel atual diretamente para o contexto de dispositivo de exibição.)  
  
 Se o **BITMAP** estrutura apontada pelo `lpBitmap` parâmetro tiver sido preenchido usando o `GetObject` função, os bits do bitmap não são especificados e o bitmap foi inicializado. Para inicializar o bitmap, um aplicativo pode usar uma função como [CDC::BitBlt](../../mfc/reference/cdc-class.md#bitblt) ou [SetDIBits](http://msdn.microsoft.com/library/windows/desktop/dd162973) para copiar os bits do bitmap identificado pelo primeiro parâmetro de `CGdiObject::GetObject` no bitmap criado por `CreateBitmapIndirect`.  
  
 Quando você terminar com a `CBitmap` objeto criado com `CreateBitmapIndirect` funcionar, primeiro selecione o bitmap fora do contexto de dispositivo, excluir o `CBitmap` objeto.  
  
##  <a name="a-namecreatecompatiblebitmapa--cbitmapcreatecompatiblebitmap"></a><a name="createcompatiblebitmap"></a>CBitmap::CreateCompatibleBitmap  
 Inicializa um bitmap que é compatível com o dispositivo especificado pelo `pDC`.  
  
```  
BOOL CreateCompatibleBitmap(
    CDC* pDC,  
    int nWidth,  
    int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Especifica o contexto de dispositivo.  
  
 `nWidth`  
 Especifica a largura (em pixels) do bitmap.  
  
 `nHeight`  
 Especifica a altura (em pixels) do bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O bitmap tem o mesmo número de planos de cores ou o mesmo formato de bits por pixel como o contexto de dispositivo especificado. Ele pode ser selecionado como o bitmap atual para qualquer dispositivo de memória que é compatível com o especificado pelo `pDC`.  
  
 Se `pDC` é um contexto de dispositivo de memória, o bitmap retornado tem o mesmo formato que o bitmap selecionado nesse contexto de dispositivo. Um contexto de dispositivo"memória" é um bloco de memória que representa uma superfície de exibição. Ele pode ser usado para preparar imagens na memória antes de copiá-los para a superfície de exibição real do dispositivo compatível.  
  
 Quando um contexto de dispositivo de memória é criado, GDI seleciona automaticamente um bitmap monocromático de estoque para ele.  
  
 Como um contexto de dispositivo de memória de cor pode ter cor ou bitmaps monocromático selecionado, o formato do bitmap retornado pelo `CreateCompatibleBitmap` função não é sempre a mesma; no entanto, o formato de um bitmap compatível para um contexto de dispositivo nonmemory é sempre no formato do dispositivo.  
  
 Quando você terminar com a `CBitmap` objeto criado com o `CreateCompatibleBitmap` funcionar, primeiro selecione o bitmap fora do contexto de dispositivo, excluir o `CBitmap` objeto.  
  
##  <a name="a-namecreatediscardablebitmapa--cbitmapcreatediscardablebitmap"></a><a name="creatediscardablebitmap"></a>CBitmap::CreateDiscardableBitmap  
 Inicializa um bitmap descartável que é compatível com o contexto de dispositivo identificado pelo `pDC`.  
  
```  
BOOL CreateDiscardableBitmap(
    CDC* pDC,  
    int nWidth,  
    int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Especifica um contexto de dispositivo.  
  
 `nWidth`  
 Especifica a largura (em bits) do bitmap.  
  
 `nHeight`  
 Especifica a altura (em bits) do bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O bitmap tem o mesmo número de planos de cores ou o mesmo formato de bits por pixel como o contexto de dispositivo especificado. Um aplicativo pode selecionar esse bitmap como o bitmap atual para um dispositivo de memória que é compatível com o especificado pelo `pDC`.  
  
 Windows pode descartar um bitmap criado por essa função somente se não tiver selecionado um aplicativo em um contexto de exibição. Se o Windows descarta o bitmap quando não estiver selecionada e o aplicativo mais tarde tenta selecioná-la, o [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) função retornará **nulo**.  
  
 Quando você terminar com a `CBitmap` objeto criado com o `CreateDiscardableBitmap` funcionar, primeiro selecione o bitmap fora do contexto de dispositivo, excluir o `CBitmap` objeto.  
  
##  <a name="a-namefromhandlea--cbitmapfromhandle"></a><a name="fromhandle"></a>CBitmap::FromHandle  
 Retorna um ponteiro para um `CBitmap` objeto quando recebe um identificador para um bitmap GDI do Windows.  
  
```  
static CBitmap* PASCAL FromHandle(HBITMAP hBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hBitmap`  
 Especifica um bitmap GDI do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CBitmap` objeto se bem-sucedido; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se um `CBitmap` objeto já não está anexado ao identificador, um temporário `CBitmap` objeto é criado e anexado. Esse temporário `CBitmap` objeto é válido somente até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, em que ponto gráfico temporário todos os objetos são excluídos. Outra maneira de dizer isso é que o objeto temporário só é válido durante o processamento da mensagem de uma janela.  
  
##  <a name="a-namegetbitmapa--cbitmapgetbitmap"></a><a name="getbitmap"></a>CBitmap::GetBitmap  
 Recupera propriedades da imagem do bitmap anexado.  
  
```  
int GetBitmap(BITMAP* pBitMap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBitMap`  
 Ponteiro para uma [estrutura BITMAP](../../mfc/reference/bitmap-structure.md) estrutura que receberá as propriedades da imagem. Esse parâmetro não deve ser `NULL`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método teve êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetbitmapbitsa--cbitmapgetbitmapbits"></a><a name="getbitmapbits"></a>CBitmap::GetBitmapBits  
 Copia o padrão de bits do bitmap anexado no buffer especificado.  
  
```  
DWORD GetBitmapBits(
    DWORD dwCount,  
    LPVOID lpBits) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCount`  
 O número de bytes a serem copiados para o buffer.  
  
 `lpBits`  
 Ponteiro para o buffer que receberá o bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes copiados para o buffer se o método teve êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use [CBitmap::GetBitmap](#getbitmap) para determinar o tamanho do buffer necessário.  
  
##  <a name="a-namegetbitmapdimensiona--cbitmapgetbitmapdimension"></a><a name="getbitmapdimension"></a>CBitmap::GetBitmapDimension  
 Retorna a largura e altura do bitmap.  
  
```  
CSize GetBitmapDimension() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura e altura do bitmap, medido em unidades de 0,1 milímetros. A altura é no **cy** membro do `CSize` objeto e a largura está no **cx** membro. Se a altura e largura de bitmap não foram definidas usando `SetBitmapDimension`, o valor de retorno é 0.  
  
### <a name="remarks"></a>Comentários  
 A altura e largura são considerados tiver sido definido anteriormente usando o [SetBitmapDimension](#setbitmapdimension) função de membro.  
  
##  <a name="a-nameloadbitmapa--cbitmaploadbitmap"></a><a name="loadbitmap"></a>CBitmap::LoadBitmap  
 Carrega o recurso de bitmap nomeado pelo `lpszResourceName` ou identificado pelo número do ID de `nIDResource` do arquivo executável do aplicativo.  
  
```  
BOOL LoadBitmap(LPCTSTR lpszResourceName);  
BOOL LoadBitmap(UINT nIDResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszResourceName`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de bitmap.  
  
 `nIDResource`  
 Especifica o número de identificação de recurso do recurso de bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O bitmap carregado está associado a `CBitmap` objeto.  
  
 Se o bitmap identificado por `lpszResourceName` não existir ou se não houver memória suficiente para carregar o bitmap, a função retornará 0.  
  
 Você pode usar o [CGdiObject::DeleteObject](../../mfc/reference/cgdiobject-class.md#deleteobject) função excluir bitmap carregado pelo `LoadBitmap` função, ou o `CBitmap` destruidor excluirá o objeto para você.  
  
> [!CAUTION]
>  Antes de excluir o objeto, certifique-se de não estiver em um contexto de dispositivo.  
  
 Os bitmaps a seguir foram adicionados às versões do Windows 3.1 e posteriores:  
  
 **OBM_UPARRROWIOBM_DNARROWIOBM_RGARROWIOBM_LFARROWI**  
  
 Esses bitmaps não são encontrados em drivers de dispositivo para versões do Windows 3.0 e versões anteriores. Para obter uma lista completa de bitmaps e uma exibição de sua aparência, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameloadmappedbitmapa--cbitmaploadmappedbitmap"></a><a name="loadmappedbitmap"></a>CBitmap::LoadMappedBitmap  
 Chame essa função de membro para carregar um bitmap e mapear as cores para as cores do sistema atual.  
  
```  
BOOL LoadMappedBitmap(
    UINT nIDBitmap,  
    UINT nFlags = 0,  
    LPCOLORMAP lpColorMap = NULL,  
    int nMapSize = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDBitmap`  
 A ID do recurso de bitmap.  
  
 `nFlags`  
 Um sinalizador para um bitmap. Pode ser zero ou **CMB_MASKED**.  
  
 `lpColorMap`  
 Um ponteiro para um **substituição** estrutura que contém as informações de cor necessárias para mapear os bitmaps. Se esse parâmetro for **nulo**, a função usa o mapa de cores padrão.  
  
 *nMapSize*  
 O número de mapas de cor apontada por `lpColorMap`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `LoadMappedBitmap` mapeará as cores usadas em glifos de botão.  
  
 Para obter informações sobre como criar um bitmap mapeado, consulte a função do Windows [CreateMappedBitmap](http://go.microsoft.com/fwlink/linkid=230562) e [substituição](http://msdn.microsoft.com/library/windows/desktop/bb760448) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameloadoembitmapa--cbitmaploadoembitmap"></a><a name="loadoembitmap"></a>CBitmap::LoadOEMBitmap  
 Carrega um bitmap predefinido usado pelo Windows.  
  
```  
BOOL LoadOEMBitmap(UINT nIDBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDBitmap`  
 Número de identificação do bitmap Windows predefinido. Os valores possíveis estão listados abaixo do WINDOWS. H:  
  
|||  
|-|-|  
|**OBM_BTNCORNERS**|**OBM_OLD_RESTORE**|  
|**OBM_BTSIZE**|**OBM_OLD_RGARROW**|  
|**OBM_CHECK**|**OBM_OLD_UPARROW**|  
|**OBM_CHECKBOXES**|**OBM_OLD_ZOOM**|  
|**OBM_CLOSE**|**OBM_REDUCE**|  
|**OBM_COMBO**|**OBM_REDUCED**|  
|**OBM_DNARROW**|**OBM_RESTORE**|  
|**OBM_DNARROWD**|**OBM_RESTORED**|  
|**OBM_DNARROWI**|**OBM_RGARROW**|  
|**OBM_LFARROW**|**OBM_RGARROWD**|  
|**OBM_LFARROWD**|**OBM_RGARROWI**|  
|**OBM_LFARROWI**|**OBM_SIZE**|  
|**OBM_MNARROW**|**OBM_UPARROW**|  
|**OBM_OLD_CLOSE**|**OBM_UPARROWD**|  
|**OBM_OLD_DNARROW**|**OBM_UPARROW**|  
|**OBM_OLD_LFARROW**|**OBM_ZOOM**|  
|**OBM_OLD_REDUCE**|**OBM_ZOOMD**|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Bitmap nomes que começam com **OBM_OLD** representam os bitmaps usados pelas versões do Windows anteriores a 3.0.  
  
 Observe que a constante **OEMRESOURCE** deve ser definida antes de incluir o WINDOWS. H para usar qualquer do **OBM_** constantes.  
  
##  <a name="a-nameoperatorhbitmapa--cbitmapoperator-hbitmap"></a><a name="operator_hbitmap"></a>CBitmap::operator HBITMAP  
 Usar esse operador para obter o identificador do Windows GDI anexado do `CBitmap` objeto.  
  
```  
operator HBITMAP() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um identificador para o objeto Windows GDI representado pelo `CBitmap` objeto; caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Este operador é um operador de conversão, que oferece suporte ao uso direto de um `HBITMAP` objeto.  
  
 Para obter mais informações sobre como usar objetos gráficos, consulte [objetos de gráfico](http://msdn.microsoft.com/library/windows/desktop/dd144962) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetbitmapbitsa--cbitmapsetbitmapbits"></a><a name="setbitmapbits"></a>CBitmap::SetBitmapBits  
 Define os bits de um bitmap com os valores de bit fornecidos pelo `lpBits`.  
  
```  
DWORD SetBitmapBits(
    DWORD dwCount,  
    const void* lpBits);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCount`  
 Especifica o número de bytes apontada por `lpBits`.  
  
 `lpBits`  
 Aponta para a **bytes** matriz que contém os valores de pixels a serem copiados para o `CBitmap` objeto. Em ordem para o bitmap poder processar sua imagem corretamente, os valores devem ser formatados de acordo com os valores de intensidade de altura, largura e cor que foram especificados quando a instância CBitmap foi criada. Para obter mais informações, consulte [CBitmap::CreateBitmap](#createbitmap).  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes usados na configuração os bits do bitmap; 0 se a função falhar.  
  
##  <a name="a-namesetbitmapdimensiona--cbitmapsetbitmapdimension"></a><a name="setbitmapdimension"></a>CBitmap::SetBitmapDimension  
 Atribui uma largura e altura de um bitmap em unidades de 0,1 milímetros.  
  
```  
CSize SetBitmapDimension(
    int nWidth,  
    int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nWidth`  
 Especifica a largura do bitmap (em unidades de 0,1 milímetro).  
  
 `nHeight`  
 Especifica a altura do bitmap (em unidades de 0,1 milímetro).  
  
### <a name="return-value"></a>Valor de retorno  
 As dimensões de bitmap anterior. Altura é no **cy** variável de membro do `CSize` objeto e largura está no **cx** variável de membro.  
  
### <a name="remarks"></a>Comentários  
 A GDI não usa esses valores, exceto to retorná-los quando um aplicativo chama o [GetBitmapDimension](#getbitmapdimension) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Classe CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)


