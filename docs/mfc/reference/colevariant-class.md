---
title: Classe COleVariant
ms.date: 11/04/2016
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
helpviewer_keywords:
- COleVariant [MFC], COleVariant
- COleVariant [MFC], Attach
- COleVariant [MFC], ChangeType
- COleVariant [MFC], Clear
- COleVariant [MFC], Detach
- COleVariant [MFC], GetByteArrayFromVariantArray
- COleVariant [MFC], SetString
ms.assetid: e1b5cd4a-b066-4b9b-b48b-6215ed52d998
ms.openlocfilehash: 7d8abea39a9baa3f447ca0d5f3ab1183367d531f
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753715"
---
# <a name="colevariant-class"></a>Classe COleVariant

Encapsula o tipo de dados [VARIANT.](/windows/win32/api/oaidl/ns-oaidl-variant)

## <a name="syntax"></a>Sintaxe

```
class COleVariant : public tagVARIANT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleVariant::COleVariant](#colevariant)|Constrói um objeto `COleVariant`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleVariant::Anexar](#attach)|Anexa uma VARIANT `COleVariant`A .|
|[COleVariant::ChangeType](#changetype)|Altera o tipo `COleVariant` variante deste objeto.|
|[COleVariant::Clear](#clear)|Limpa esse objeto `COleVariant`.|
|[COleVariant::Detach](#detach)|Destaca uma VARIANTE `COleVariant` de a e retorna a VARIANT.|
|[COleVariant::GetByteArrayFromVariantArrayArray](#getbytearrayfromvariantarray)|Recupera uma matriz de bytes de uma matriz de variantes existente.|
|[COleVariant::SetString](#setstring)|Define a string para um tipo específico, tipicamente ANSI.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleVariant::operador LPCVARIANT](#operator_lpcvariant)|Converte `COleVariant` um valor `LPCVARIANT`em um .|
|[COleVariant::operador LPVARIANT](#operator_lpvariant)|Converte `COleVariant` um objeto `LPVARIANT`em um .|
|[COleVariante::operador =](#operator_eq)|Copia `COleVariant` um valor.|
|[COleVariante::operador ==](#operator_eq_eq)|Compara `COleVariant` dois valores.|
|[COleVariant::operador, &lt; &lt;&gt;&gt;](#operator_lt_lt__gt_gt)|Produz um `COleVariant` valor `CArchive` `CDumpContext` para ou `COleVariant` e `CArchive`insere um objeto de .|

## <a name="remarks"></a>Comentários

Este tipo de dados é usado na automação OLE. Especificamente, a estrutura [DISPPARAMS](/windows/win32/api/oaidl/ns-oaidl-dispparams) contém um ponteiro para uma matriz de estruturas VARIANT. Uma `DISPPARAMS` estrutura é usada para passar parâmetros para [IDispatch::Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke).

> [!NOTE]
> Esta classe é derivada da `VARIANT` estrutura. Isso significa que `COleVariant` você pode passar um `VARIANT` parâmetro que exige a `VARIANT` e que os `COleVariant`membros de dados da estrutura são membros de dados acessíveis de .

As duas classes MFC relacionadas [COleCurrency](../../mfc/reference/colecurrency-class.md) e [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) encapsulam os tipos de dados variantes CURRENCY ( `VT_CY`) e DATE ( `VT_DATE`). A `COleVariant` classe é usada extensivamente nas classes DAO; veja essas classes para uso típico desta classe, por [exemplo, CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

Para obter mais informações, consulte a [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant), [CURRENCY,](/windows/win32/api/wtypes/ns-wtypes-cy~r1) [DISPPARAMS](/windows/win32/api/oaidl/ns-oaidl-dispparams)e [IDispatch::Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) entradas no Windows SDK.

Para obter mais `COleVariant` informações sobre a classe e seu uso na automação OLE, consulte "Parâmetros de Passagem na Automação OLE" no artigo [Automação](../../mfc/automation.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagVARIANT`

`COleVariant`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="colevariantattach"></a><a name="attach"></a>COleVariant::Anexar

Chame esta função para [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) anexar o `COleVariant` objeto VARIANT dado ao objeto atual.

```cpp
void Attach(VARIANT& varSrc);
```

### <a name="parameters"></a>Parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um objeto `VARIANT` existente a ser anexado ao objeto atual. `COleVariant`

### <a name="remarks"></a>Comentários

Esta função define o VARTYPE do *varSrc* para VT_EMPTY.

Para obter mais informações, consulte as [entradas VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) e [VARENUM](/windows/win32/api/wtypes/ne-wtypes-varenum) no Windows SDK.

## <a name="colevariantcolevariant"></a><a name="colevariant"></a>COleVariant::COleVariant

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

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um objeto `COleVariant` `VARIANT` existente ou a ser `COleVariant` copiado para o novo objeto.

*Psrc*<br/>
Um ponteiro `VARIANT` para um objeto que será `COleVariant` copiado para o novo objeto.

*lpszSrc*<br/>
Uma seqüência de terminadas nula `COleVariant` a ser copiada para o novo objeto.

*Vtsrc*<br/>
O `VARTYPE` para `COleVariant` o novo objeto.

*strSrc*<br/>
Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) a ser `COleVariant` copiado para o novo objeto.

*nSrc*, *lSrc* Um valor numérico a `COleVariant` ser copiado para o novo objeto.

*Vtsrc*<br/>
O `VARTYPE` para `COleVariant` o novo objeto.

*curSrc*<br/>
Um objeto [COleCurrency](../../mfc/reference/colecurrency-class.md) a ser `COleVariant` copiado para o novo objeto.

*fltSrc,* *dblSrc*<br/>
Um valor numérico a ser copiado no novo objeto `COleVariant`.

*timeSrc*<br/>
Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) a ser `COleVariant` copiado no novo objeto.

*arrSrc*<br/>
Um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) a ser `COleVariant` copiado para o novo objeto.

*LBSRC*<br/>
Um objeto [CLongBinary](../../mfc/reference/clongbinary-class.md) a ser `COleVariant` copiado para o novo objeto.

*Pidl*<br/>
Um ponteiro para uma estrutura [ITEMIDLIST](/windows/win32/api/shtypes/ns-shtypes-itemidlist) a `COleVariant` ser copiado para o novo objeto.

### <a name="remarks"></a>Comentários

Todos esses construtores `COleVariant` criam novos objetos inicializados para o valor especificado. Segue-se uma breve descrição de cada um desses construtores.

- **COleVariant** Cria um `COleVariant` objeto vazio, VT_EMPTY.

- **COleVariant** *(varSrc)* **)** Copia um `VARIANT` objeto `COleVariant` ou existente. O tipo de variante é mantido.

- **COleVariant** *(pSrc)* **)** Copia um `VARIANT` objeto `COleVariant` ou existente. O tipo de variante é mantido.

- **COleVariant** *(lpszSrc* **)** Copia uma seqüência de string no novo objeto, VT_BSTR (UNICODE).

- **COleVariant** *(lpszSrc,* **,** *vtSrc* **)** Copia uma corda no novo objeto. O parâmetro *vtSrc* deve ser VT_BSTR (UNICODE) ou VT_BSTRT (ANSI).

- **COleVariant** *(strSrc)* **)** Copia uma seqüência de string no novo objeto, VT_BSTR (UNICODE).

- **COleVariant** *(nSrc)* **)** Copia um inteiro de 8 bits no novo objeto, VT_UI1.

- **COleVariant** *(nSrc,* **,** *vtSrc* **)** Copia um inteiro de 16 bits (ou valor booleano) no novo objeto. O parâmetro *vtSrc* deve ser VT_I2 ou VT_BOOL.

- **COleVariant** *(lSrc* **,** *vtSrc* **)** Copia um inteiro de 32 bits (ou valor SCODE) no novo objeto. O parâmetro *vtSrc* deve ser VT_I4, VT_ERROR ou VT_BOOL.

- **COleVariant** *(curSrc)* **)** Copia `COleCurrency` um valor no novo objeto, VT_CY.

- **COleVariant** *(fltSrc)* **)** Copia um valor de ponto flutuante de 32 bits no novo objeto, VT_R4.

- **COleVariant** *(dblSrc)* **)** Copia um valor de ponto flutuante de 64 bits no novo objeto, VT_R8.

- **COleVariant** *(timeSrc)* **)** Copia `COleDateTime` um valor no novo objeto, VT_DATE.

- **COleVariant** *(arrSrc)* **)** Copia `CByteArray` um objeto no novo objeto, VT_EMPTY.

- **COleVariant** *(lbSrc)* **)** Copia `CLongBinary` um objeto no novo objeto, VT_EMPTY.

Para obter mais informações sobre o SCODE, consulte [Estrutura de Códigos de erro COM](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

## <a name="colevariantchangetype"></a><a name="changetype"></a>COleVariant::ChangeType

Converte o tipo de `COleVariant` valor de variante neste objeto.

```cpp
void ChangeType(VARTYPE vartype, LPVARIANT pSrc = NULL);
```

### <a name="parameters"></a>Parâmetros

*Vartype*<br/>
O VARTYPE `COleVariant` para este objeto.

*Psrc*<br/>
Um ponteiro para o objeto [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) a ser convertido. Se esse valor for `COleVariant` NULO, este objeto será usado como fonte para a conversão.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte as [entradas VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant), [VARENUM](/windows/win32/api/wtypes/ne-wtypes-varenum)e [VariantChangeType](/windows/win32/api/oleauto/nf-oleauto-variantchangetype) no SDK do Windows.

## <a name="colevariantclear"></a><a name="clear"></a>COleVariant::Clear

Limpa o `VARIANT`.

```cpp
void Clear();
```

### <a name="remarks"></a>Comentários

Isso define o VARTYPE para que este objeto VT_EMPTY. O `COleVariant` destruidor chama essa função.

Para obter mais `VARIANT`informações, consulte `VariantClear` o VARTYPE e as entradas no Windows SDK.

## <a name="colevariantdetach"></a><a name="detach"></a>COleVariant::Detach

Destaca o objeto [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) subjacente `COleVariant` deste objeto.

```
VARIANT Detach();
```

### <a name="remarks"></a>Comentários

Esta função define o `COleVariant` VARTYPE para que este objeto VT_EMPTY.

> [!NOTE]
> Após `Detach`a chamada, é responsabilidade do `VariantClear` chamador `VARIANT` chamar a estrutura resultante.

Para obter mais informações, consulte as [entradas VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant), [VARENUM](/windows/win32/api/wtypes/ne-wtypes-varenum)e [VariantClear](/windows/win32/api/oleauto/nf-oleauto-variantclear) no SDK do Windows.

## <a name="colevariantgetbytearrayfromvariantarray"></a><a name="getbytearrayfromvariantarray"></a>COleVariant::GetByteArrayFromVariantArrayArray

Recupera uma matriz de bytes de uma matriz de variantes existente

```cpp
void GetByteArrayFromVariantArray(CByteArray& bytes);
```

### <a name="parameters"></a>Parâmetros

*Bytes*<br/>
Uma referência a um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) existente.

## <a name="colevariantoperator-lpcvariant"></a><a name="operator_lpcvariant"></a>COleVariant::operador LPCVARIANT

Este operador de `VARIANT` fundição retorna uma `COleVariant` estrutura cujo valor é copiado deste objeto.

```
operator LPCVARIANT() const;
```

### <a name="remarks"></a>Comentários

## <a name="colevariantoperator-lpvariant"></a><a name="operator_lpvariant"></a>COleVariant::operador LPVARIANT

Chame este operador de fundição para acessar a estrutura subjacente `VARIANT` para este `COleVariant` objeto.

```
operator LPVARIANT();
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
> Alterar o valor `VARIANT` na estrutura acessada pelo ponteiro retornado `COleVariant` por esta função mudará o valor deste objeto.

## <a name="colevariantoperator-"></a><a name="operator_eq"></a>COleVariante::operador =

Esses operadores de atribuição sobrecarregados `COleVariant` copiam o valor de origem para este objeto.

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

Segue-se uma breve descrição de cada operador:

- operador *=(varSrc* **operator =(** **)** Copia uma VARIANT `COleVariant` ou objeto existente para este objeto.

- operador *=(pSrc* **operator =(** **)** Copia o objeto VARIANT acessado pelo *pSrc* para este objeto.

- operador *=(lpszSrc* **)** **operator =(** Copia uma seqüência de terminadas nula para este objeto e define o VARTYPE para VT_BSTR.

- operador *=(strSrc* **operator =(** **)** Copia um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) para este objeto e define o VARTYPE como VT_BSTR.

- operador *=(nSrc* **operator =(** **)** Copia um valor inteiro de 8 ou 16 bits neste objeto. Se *nSrc* é um valor de 8 bits, o VARTYPE deste é definido para VT_UI1. Se *o nSrc* é um valor de 16 bits e o VARTYPE disso é VT_BOOL, ele é mantido; caso contrário, está definido para VT_I2.

- **operador =(** *lSrc* **)** Copia um valor inteiro de 32 bits para este objeto. Se o VARTYPE disso é VT_ERROR, ele é mantido; caso contrário, está definido para VT_I4.

- **operador =(curSrc** *curSrc* **)** Copia um objeto [COleCurrency](../../mfc/reference/colecurrency-class.md) para este objeto e define o VARTYPE como VT_CY.

- operador *=(fltSrc* **)** **operator =(** Copia um valor de ponto flutuante de 32 bits para este objeto e define o VARTYPE para VT_R4.

- operador *=(dblSrc* **)** **operator =(** Copia um valor de ponto flutuante de 64 bits para este objeto e define o VARTYPE para VT_R8.

- operador *=(dateSrc* **operator =(** **)** Copia um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) para este objeto e define o VARTYPE para VT_DATE.

- operador *=(arrSrc* **)** **operator =(** Copia um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) para este `COleVariant` objeto.

- operador *=(lbSrc* **operator =(** **)** Copia um objeto [CLongBinary](../../mfc/reference/clongbinary-class.md) para este `COleVariant` objeto.

Para obter mais informações, consulte as [entradas VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) e [VARENUM](/windows/win32/api/wtypes/ne-wtypes-varenum) no Windows SDK.

## <a name="colevariantoperator-"></a><a name="operator_eq_eq"></a>COleVariante::operador ==

Este operador compara dois valores de variante e retorna não zero se forem iguais; caso contrário, 0.

```
BOOL operator==(const VARIANT& varSrc) const;
BOOL operator==(LPCVARIANT pSrc) const;
```

## <a name="colevariantoperator-ltlt-gtgt"></a><a name="operator_lt_lt__gt_gt"></a>COleVariant::operador, &lt; &lt;&gt;&gt;

Produz um `COleVariant` valor `CArchive` `CdumpContext` para ou `COleVariant` e `CArchive`insere um objeto de .

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

O `COleVariant` operador**\<** de inserção ( ) suporta dumping diagnóstico e armazenamento em um arquivo. O operador**>>** de extração ( ) suporta o carregamento de um arquivo.

## <a name="colevariantsetstring"></a><a name="setstring"></a>COleVariant::SetString

Define a seqüência para um tipo específico.

```cpp
void SetString(LPCTSTR lpszSrc, VARTYPE vtSrc);
```

### <a name="parameters"></a>Parâmetros

*lpszSrc*<br/>
Uma seqüência de terminadas nula `COleVariant` a ser copiada para o novo objeto.

*Vtsrc*<br/>
O VARTYPE para `COleVariant` o novo objeto.

### <a name="remarks"></a>Comentários

O parâmetro *vtSrc* deve ser VT_BSTR (UNICODE) ou VT_BSTRT (ANSI). `SetString`é normalmente usado para definir strings para ANSI, uma vez que o padrão para o [Construtor COleVariant::COleVariant](#colevariant) com um parâmetro de ponteiro de seqüência ou string e nenhum VARTYPE é UNICODE.

Um conjunto de registros DAO em uma compilação não-UNICODE espera que as strings sejam ANSI. Assim, para funções DAO que `COleVariant` usam objetos, se você não estiver criando um conjunto de registros UNICODE, você deve usar o **COleVariant::COleVariant (lpszSrc** *lpszSrc* `SetString` **,** *vtSrc* **)** forma de construtor com *vtSrc* definido para VT_BSTRT (ANSI) ou usar com *vtSrc* definido para VT_BSTRT para fazer strings ANSI. Por exemplo, `CDaoRecordset` as funções [CDaoRecordset::Seek](../../mfc/reference/cdaorecordset-class.md#seek) e [CDaoRecordset::SetFieldValue](../../mfc/reference/cdaorecordset-class.md#setfieldvalue) usam `COleVariant` objetos como parâmetros. Esses objetos devem ser ANSI se o conjunto de registros DAO não for UNICODE.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
