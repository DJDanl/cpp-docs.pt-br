---
title: Classe COleVariant | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleVariant
- AFXDISP/COleVariant
- AFXDISP/COleVariant::COleVariant
- AFXDISP/COleVariant::Attach
- AFXDISP/COleVariant::ChangeType
- AFXDISP/COleVariant::Clear
- AFXDISP/COleVariant::Detach
- AFXDISP/COleVariant::GetByteArrayFromVariantArray
- AFXDISP/COleVariant::SetString
dev_langs:
- C++
helpviewer_keywords:
- COleVariant [MFC], COleVariant
- COleVariant [MFC], Attach
- COleVariant [MFC], ChangeType
- COleVariant [MFC], Clear
- COleVariant [MFC], Detach
- COleVariant [MFC], GetByteArrayFromVariantArray
- COleVariant [MFC], SetString
ms.assetid: e1b5cd4a-b066-4b9b-b48b-6215ed52d998
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8b7501adf2f424f2232df05e26f5d0ac4a35158c
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42543090"
---
# <a name="colevariant-class"></a>Classe COleVariant
Encapsula o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) tipo de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleVariant : public tagVARIANT  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleVariant::COleVariant](#colevariant)|Constrói um objeto `COleVariant`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleVariant::Attach](#attach)|Anexa uma VARIANTE para um `COleVariant`.|  
|[COleVariant::ChangeType](#changetype)|Altera o tipo de variante isso `COleVariant` objeto.|  
|[COleVariant::Clear](#clear)|Limpa esse objeto `COleVariant`.|  
|[COleVariant::Detach](#detach)|Desconecta uma VARIANTE de um `COleVariant` e retorna a variação.|  
|[COleVariant::GetByteArrayFromVariantArray](#getbytearrayfromvariantarray)|Recupera uma matriz de bytes de uma matriz de variant existente.|  
|[COleVariant::SetString](#setstring)|Define a cadeia de caracteres para um tipo específico, normalmente ANSI.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleVariant::operator LPCVARIANT](#operator_lpcvariant)|Converte um `COleVariant` de valor em um `LPCVARIANT`.|  
|[COleVariant::operator LPVARIANT](#operator_lpvariant)|Converte um `COleVariant` do objeto em um `LPVARIANT`.|  
|[COleVariant::operator =](#operator_eq)|Copia um `COleVariant` valor.|  
|[COleVariant::operator = =](#operator_eq_eq)|Compara dois `COleVariant` valores.|  
|[COleVariant::operator &lt; &lt;, &gt;&gt;](#operator_lt_lt__gt_gt)|Saídas de um `COleVariant` valor para `CArchive` ou `CDumpContext` e insere um `COleVariant` do objeto de `CArchive`.|  
  
## <a name="remarks"></a>Comentários  
 Esse tipo de dados é usado na automação OLE. Especificamente, o [DISPPARAMS](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagdispparams) estrutura contém um ponteiro para uma matriz de estruturas de VARIANTE. Um `DISPPARAMS` estrutura é usada para passar parâmetros para [IDispatch:: Invoke](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).  
  
> [!NOTE]
>  Essa classe é derivada de `VARIANT` estrutura. Isso significa que você pode passar uma `COleVariant` em um parâmetro que chama uma `VARIANT` e que os membros de dados de `VARIANT` estrutura são membros de dados acessíveis de `COleVariant`.  
  
 Os dois relacionados classes MFC [COleCurrency](../../mfc/reference/colecurrency-class.md) e [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) encapsulam os tipos de dados variant moeda ( `VT_CY`) e data ( `VT_DATE`). O `COleVariant` classe é amplamente usado nas classes DAO; consulte essas classes para uso típico dessa classe, por exemplo [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
 Para obter mais informações, consulte o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant), [moeda](http://msdn.microsoft.com/5e81273c-7289-45c7-93c0-32c1553f708e), [DISPPARAMS](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagdispparams), e [IDispatch:: Invoke](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) entradas no SDK do Windows.  
  
 Para obter mais informações sobre o `COleVariant` classe e seu uso na automação OLE, consulte "Passando parâmetros na automação OLE" no artigo [automação](../../mfc/automation.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tagVARIANT`  
  
 `COleVariant`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="attach"></a>  COleVariant::Attach  
 Chame essa função para anexar a determinada [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) objeto atual `COleVariant` objeto.  
  
```  
void Attach(VARIANT& varSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *varSrc*  
 Um existente `VARIANT` o objeto a ser anexado à atual `COleVariant` objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função define a [VARTYPE](http://msdn.microsoft.com/317b911b-1805-402d-a9cb-159546bc88b4) dos *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3* como VT_EMPTY.  
  
 Para obter mais informações, consulte o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) e [VARTYPE](http://msdn.microsoft.com/317b911b-1805-402d-a9cb-159546bc88b4) entradas no SDK do Windows.  
  
##  <a name="colevariant"></a>  COleVariant::COleVariant  
 Constrói um objeto `COleVariant`.  
  
```  
COleVariant(); 
COleVariant(const VARIANT& varSrc); 
COleVariant(const COleVariant& varSrc); 
COleVariant(LPCVARIANT pSrc); 
COleVariant(LPCTSTR lpszSrc); 
COleVariant(LPCTSTR lpszSrc, VARTYPE vtSrc); 
COleVariant(CString& strSrc); 
COleVariant(BYTE nSrc); 
COleVariant(short nSrc, VARTYPE vtSrc = VT_I2); 
COleVariant(long lSrc,VARTYPE vtSrc = VT_I4); 
COleVariant(const COleCurrency& curSrc); 
COleVariant(float fltSrc); 
COleVariant(double dblSrc); 
COleVariant(const COleDateTime& timeSrc); 
COleVariant(const CByteArray& arrSrc); 
COleVariant(const CLongBinary& lbSrc); 
COleVariant(LPCITEMIDLIST pidl);
```  
  
### <a name="parameters"></a>Parâmetros  
 *varSrc*  
 Um existente `COleVariant` ou `VARIANT` objeto a ser copiado para o novo `COleVariant` objeto.  
  
 *pSrc*  
 Um ponteiro para um `VARIANT` objeto que será copiado no novo `COleVariant` objeto.  
  
 *lpszSrc*  
 Uma cadeia de caracteres terminada em nulo a ser copiado para o novo `COleVariant` objeto.  
  
 *vtSrc*  
 O `VARTYPE` para o novo `COleVariant` objeto.  
  
 *{1&gt;strsrc*  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto a ser copiado para o novo `COleVariant` objeto.  
  
 *nSrc*, *lSrc*  
 Um valor numérico a ser copiado no novo objeto `COleVariant`.  
  
 *vtSrc*  
 O `VARTYPE` para o novo `COleVariant` objeto.  
  
 *curSrc*  
 Um [COleCurrency](../../mfc/reference/colecurrency-class.md) objeto a ser copiado para o novo `COleVariant` objeto.  
  
 *{1&gt;fltsrc*, *dblsrc&lt;1}*  
 Um valor numérico a ser copiado no novo objeto `COleVariant`.  
  
 *timeSrc*  
 Um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto a ser copiado para o novo `COleVariant` objeto.  
  
 *arrSrc*  
 Um [CByteArray](../../mfc/reference/cbytearray-class.md) objeto a ser copiado para o novo `COleVariant` objeto.  
  
 *lbSrc*  
 Um [CLongBinary](../../mfc/reference/clongbinary-class.md) objeto a ser copiado para o novo `COleVariant` objeto.  
  
 *PIDL*  
 Um ponteiro para um [ITEMIDLIST](http://msdn.microsoft.com/library/windows/desktop/bb773321) estrutura a ser copiado para o novo `COleVariant` objeto.  
  
### <a name="remarks"></a>Comentários  
 Todos esses construtores criam novos `COleVariant` objetos inicializados ao valor especificado. Segue uma breve descrição de cada um desses construtores.  
  
- **() De COleVariant** cria uma vazia `COleVariant` objeto, VT_EMPTY.  
  
- **COleVariant (** *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3* **)** copia existente `VARIANT` ou `COleVariant` objeto. O tipo de variante é mantido.  
  
- **COleVariant (** `pSrc` **)** copia existente `VARIANT` ou `COleVariant` objeto. O tipo de variante é mantido.  
  
- **COleVariant (** `lpszSrc` **)** copia uma cadeia de caracteres para o novo objeto, VT_BSTR (UNICODE).  
  
- **COleVariant (** `lpszSrc` **,** `vtSrc` **)** copia uma cadeia de caracteres para o novo objeto. O parâmetro *vtSrc* deve ser VT_BSTR (UNICODE) ou VT_BSTRT (ANSI).  
  
- **COleVariant (** `strSrc` **)** copia uma cadeia de caracteres para o novo objeto, VT_BSTR (UNICODE).  
  
- **COleVariant (** `nSrc` **)** copia um número inteiro de 8 bits para o novo objeto, VT_UI1.  
  
- **COleVariant (** `nSrc` **,** `vtSrc` **)** copia para o novo objeto de um inteiro de 16 bits (ou valor booliano). O parâmetro *vtSrc* deve ser VT_I2 ou VT_BOOL.  
  
- **COleVariant (** `lSrc` **,** `vtSrc` **)** copia para o novo objeto de um inteiro de 32 bits (ou valor SCODE). O parâmetro *vtSrc* deve ser VT_I4, VT_ERROR ou VT_BOOL.  
  
- **COleVariant (** `curSrc` **)** cópias um `COleCurrency` valor no novo objeto, VT_CY.  
  
- **COleVariant (** `fltSrc` **)** copia um valor de ponto flutuante de 32 bits para o novo objeto, VT_R4.  
  
- **COleVariant (** `dblSrc` **)** copia um valor de ponto flutuante de 64 bits para o novo objeto, VT_R8.  
  
- **COleVariant (** `timeSrc` **)** cópias um `COleDateTime` valor no novo objeto, VT_DATE.  
  
- **COleVariant (** `arrSrc` **)** cópias um `CByteArray` o objeto para o novo objeto, VT_EMPTY.  
  
- **COleVariant (** `lbSrc` **)** cópias um `CLongBinary` o objeto para o novo objeto, VT_EMPTY.  
  
 Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) no SDK do Windows.  
  
##  <a name="changetype"></a>  COleVariant::ChangeType  
 Converte o tipo de valor variant neste `COleVariant` objeto.  
  
```  
void ChangeType(VARTYPE vartype, LPVARIANT pSrc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *VarType*  
 O [VARTYPE](http://msdn.microsoft.com/317b911b-1805-402d-a9cb-159546bc88b4) para este `COleVariant` objeto.  
  
 *pSrc*  
 Um ponteiro para o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) objeto a ser convertido. Se esse valor for NULL, isso `COleVariant` objeto é usado como a origem para a conversão.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant), [VARTYPE](http://msdn.microsoft.com/317b911b-1805-402d-a9cb-159546bc88b4), e [VariantChangeType](/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantchangetype) entradas no SDK do Windows.  
  
##  <a name="clear"></a>  COleVariant::Clear  
 Limpa o `VARIANT`.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 Isso define o VARTYPE para esse objeto como VT_EMPTY. O `COleVariant` destruidor chama essa função.  
  
 Para obter mais informações, consulte o `VARIANT`, VARTYPE, e `VariantClear` entradas no SDK do Windows.  
  
##  <a name="detach"></a>  COleVariant::Detach  
 Desanexa subjacente [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) objeto deste `COleVariant` objeto.  
  
```  
VARIANT Detach();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função define a [VARTYPE](http://msdn.microsoft.com/317b911b-1805-402d-a9cb-159546bc88b4) para este `COleVariant` objeto como VT_EMPTY.  
  
> [!NOTE]
>  Depois de chamar `Detach`, é responsabilidade do chamador para chamar `VariantClear` em resultante `VARIANT` estrutura.  
  
 Para obter mais informações, consulte o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant), [VARTYPE](http://msdn.microsoft.com/317b911b-1805-402d-a9cb-159546bc88b4), e [VariantClear](/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) entradas no SDK do Windows.  
  
##  <a name="getbytearrayfromvariantarray"></a>  COleVariant::GetByteArrayFromVariantArray  
 Recupera uma matriz de bytes de uma matriz de variant existente  
  
```  
void GetByteArrayFromVariantArray(CByteArray& bytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bytes*  
 Uma referência a um existente [CByteArray](../../mfc/reference/cbytearray-class.md) objeto.  
  
##  <a name="operator_lpcvariant"></a>  COleVariant::operator LPCVARIANT  
 Esse operador de conversão retornará um `VARIANT` estrutura cujo valor é copiado deste `COleVariant` objeto.  
  
```  
operator LPCVARIANT() const; 
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="operator_lpvariant"></a>  COleVariant::operator LPVARIANT  
 Chame esse operador de conversão para acessar subjacente `VARIANT` estrutura para este `COleVariant` objeto.  
  
```  
operator LPVARIANT();
```   
  
### <a name="remarks"></a>Comentários  
  
> [!CAUTION]
>  Alterando o valor na `VARIANT` estrutura acessada pelo ponteiro retornado por essa função será alterado o valor deste `COleVariant` objeto.  
  
##  <a name="operator_eq"></a>  COleVariant::operator =  
 Esses operadores de atribuição sobrecarregados copie o valor de origem para este `COleVariant` objeto.  
  
```  
const COleVariant& operator=(const VARIANT& varSrc); 
const COleVariant& operator=(LPCVARIANT pSrc); 
const COleVariant& operator=(const COleVariant& varSrc); 
const COleVariant& operator=(const LPCTSTR lpszSrc);
const COleVariant& operator=(const CString& strSrc); 
const COleVariant& operator=(BYTE nSrc); 
const COleVariant& operator=(short nSrc); 
const COleVariant& operator=(long lSrc); 
const COleVariant& operator=(const COleCurrency& curSrc); 
const COleVariant& operator=(float fltSrc); 
const COleVariant& operator=(double dblSrc); 
const COleVariant& operator=(const COleDateTime& dateSrc); 
const COleVariant& operator=(const CByteArray& arrSrc); 
const COleVariant& operator=(const CLongBinary& lbSrc);
```  
  
### <a name="remarks"></a>Comentários  
 Segue uma breve descrição de cada operador:  
  
- **operador = (** *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3 * * *)** copia uma VARIANTE existente ou `COleVariant` o objeto para este objeto.  
  
- **operador = (** `pSrc` **)** copia o objeto de VARIANTE acessado pela *pSrc* para esse objeto.  
  
- **operador = (** `lpszSrc` **)** copia uma cadeia de caracteres terminada em nulo para esse objeto e define o VARTYPE como VT_BSTR.  
  
- **operador = (** `strSrc` **)** cópias de um [CString](../../atl-mfc-shared/reference/cstringt-class.md) o objeto para este objeto e define o VARTYPE para VT_BSTR.  
  
- **operador = (** `nSrc` **)** copia um valor de inteiro de 8 ou 16 bits para este objeto. Se *nSrc* é um valor de 8 bits, o VARTYPE isso é definido como VT_UI1. Se *nSrc* é um valor de 16 bits e o VARTYPE disso é VT_BOOL, é mantido; caso contrário, ele é definido como VT_I2.  
  
- **operador = (** `lSrc` **)** copia um valor inteiro de 32 bits para este objeto. Se o VARTYPE isso VT_ERROR, ele é mantido; Caso contrário, ele é definido como VT_I4.  
  
- **operador = (** `curSrc` **)** cópias de um [COleCurrency](../../mfc/reference/colecurrency-class.md) o objeto para este objeto e define o VARTYPE para VT_CY.  
  
- **operador = (** `fltSrc` **)** copia um valor de ponto flutuante de 32 bits para este objeto e define o VARTYPE como VT_R4.  
  
- **operador = (** `dblSrc` **)** copia um valor de ponto flutuante de 64 bits para este objeto e define o VARTYPE como VT_R8.  
  
- **operador = (** `dateSrc` **)** cópias de um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) o objeto para este objeto e define o VARTYPE para VT_DATE.  
  
- **operador = (** `arrSrc` **)** cópias de um [CByteArray](../../mfc/reference/cbytearray-class.md) objeto nesta `COleVariant` objeto.  
  
- **operador = (** `lbSrc` **)** cópias de um [CLongBinary](../../mfc/reference/clongbinary-class.md) objeto nesta `COleVariant` objeto.  
  
 Para obter mais informações, consulte o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) e [VARTYPE](http://msdn.microsoft.com/317b911b-1805-402d-a9cb-159546bc88b4) entradas no SDK do Windows.  
  
##  <a name="operator_eq_eq"></a>  COleVariant::operator = =  
 Esse operador compara dois valores variantes e retorna não zero, se eles forem iguais; Caso contrário, 0.  
  
```  
BOOL operator==(const VARIANT& varSrc) const; 
BOOL operator==(LPCVARIANT pSrc) const;
```  
  
##  <a name="operator_lt_lt__gt_gt"></a>  COleVariant::operator &lt; &lt;, &gt;&gt;  
 Saídas de um `COleVariant` valor para `CArchive` ou `CdumpContext` e insere um `COleVariant` do objeto de `CArchive`.  
  
```  
friend CDumpContext& AFXAPI operator<<(
    CDumpContext& dc,  
    OleVariant varSrc);
 
friend CArchive& AFXAPI operator<<(
    CArchive& ar,  
    COleVariant varSrc);
 
friend CArchive& AFXAPI operator>>(
    CArchive& ar,  
    COleVariant& varSrc);
```  
  
### <a name="remarks"></a>Comentários  
 O `COleVariant` inserção ( **< \<**) operador dá suporte a diagnóstico despejar e armazenar para um arquivo morto. A extração ( **>>**) operador oferece suporte ao carregamento de um arquivo.  
  
##  <a name="setstring"></a>  COleVariant::SetString  
 Define a cadeia de caracteres para um tipo específico.  
  
```  
void SetString(LPCTSTR lpszSrc, VARTYPE vtSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszSrc*  
 Uma cadeia de caracteres terminada em nulo a ser copiado para o novo `COleVariant` objeto.  
  
 *vtSrc*  
 O VARTYPE para o novo `COleVariant` objeto.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *vtSrc* deve ser VT_BSTR (UNICODE) ou VT_BSTRT (ANSI). `SetString` normalmente é usado para definir cadeias de caracteres como ANSI, desde o padrão para o [COleVariant::COleVariant](#colevariant) construtor com uma cadeia de caracteres ou parâmetro de ponteiro de cadeia de caracteres e nenhum VARTYPE é UNICODE.  
  
 Um conjunto de registros DAO em uma compilação de não-UNICODE espera que cadeias de caracteres serão ANSI. Portanto, para DAO funções que usam `COleVariant` objetos, se você não estiver criando um conjunto de registros UNICODE, você deve usar o **COleVariant::COleVariant (** `lpszSrc` **,** `vtSrc` **)**  formulário de construtor com *vtSrc* defina VT_BSTRT (ANSI) ou use `SetString` com *vtSrc* definido como VT_BSTRT para tornar as cadeias de caracteres ANSI. Por exemplo, o `CDaoRecordset` funções [CDaoRecordset::Seek](../../mfc/reference/cdaorecordset-class.md#seek) e [CDaoRecordset::SetFieldValue](../../mfc/reference/cdaorecordset-class.md#setfieldvalue) usar `COleVariant` objetos como parâmetros. Esses objetos devem ser ANSI, se o conjunto de registros DAO não for UNICODE.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



