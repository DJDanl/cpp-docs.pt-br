---
title: Classe CWinFormsControl
ms.date: 11/04/2016
f1_keywords:
- CWinFormsControl
- AFXWINFORMS/CWinFormsControl
- AFXWINFORMS/CWinFormsControl::CWinFormsControl
- AFXWINFORMS/CWinFormsControl::CreateManagedControl
- AFXWINFORMS/CWinFormsControl::GetControl
- AFXWINFORMS/CWinFormsControl::GetControlHandle
helpviewer_keywords:
- CWinFormsControl [MFC], CWinFormsControl
- CWinFormsControl [MFC], CreateManagedControl
- CWinFormsControl [MFC], GetControl
- CWinFormsControl [MFC], GetControlHandle
ms.assetid: 6406dd7b-fb89-4a18-ac3a-c010d6b6289a
ms.openlocfilehash: c91f50be1ea30efac81ff67c43633bedd7b0ca03
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377175"
---
# <a name="cwinformscontrol-class"></a>Classe CWinFormsControl

Fornece a funcionalidade básica para hospedagem de um controle do Windows Forms.

## <a name="syntax"></a>Sintaxe

```
template<class TManagedControl>
class CWinFormsControl : public CWnd
```

#### <a name="parameters"></a>Parâmetros

*TManagedControl*<br/>
Um controle .NET Framework Windows Forms a ser exibido no aplicativo MFC.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsControl::CWinFormsControl](#cwinformscontrol)|Constrói um objeto de wrapper de controle MFC Windows Forms.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsControl::CreateManagedControl](#createmanagedcontrol)|Cria um controle de Formulários do Windows em um contêiner MFC.|
|[CWinFormsControl::GetControl](#getcontrol)|Recupera um ponteiro para o controle do Windows Forms.|
|[CWinFormsControl::GetControlHandle](#getcontrolhandle)|Recupera uma alça para o controle do Windows Forms.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsControl::operador -&gt;](#operator_-_gt)|Substitui [CWinFormsControl::GetControl](#getcontrol) em expressões.|
|[CWinFormsControl:operador TManagedControl^](#operator_tmanagedcontrol)|Lança um tipo como ponteiro para um controle do Windows Forms.|

## <a name="remarks"></a>Comentários

A `CWinFormsControl` classe fornece a funcionalidade básica para hospedagem de um controle do Windows Forms.

Para obter mais informações sobre o uso do Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

O código MFC não deve armazenar as `m_hWnd`alças da janela (geralmente armazenadas em ). Algumas propriedades de controle do Windows Forms `Window` exigem que o `DestroyWindow` Win32 subjacente seja destruído e recriado usando e `CreateWindow`. A implementação do MFC `Destroy` `Create` Windows Forms lida com `m_hWnd` os eventos dos controles para atualizar o membro.

> [!NOTE]
> A integração do MFC Windows Forms funciona apenas em projetos que se conectam dinamicamente com o MFC (no qual o AFXDLL é definido).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h

## <a name="cwinformscontrolcreatemanagedcontrol"></a><a name="createmanagedcontrol"></a>CWinFormsControl::CreateManagedControl

Cria um controle de Formulários do Windows em um contêiner MFC.

```
inline BOOL CreateManagedControl(
    System::Type^ pType,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    int nID)
inline BOOL CreateManagedControl(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    int nID);

inline BOOL CreateManagedControl(
    DWORD dwStyle,
    int nPlaceHolderID,
    CWnd* pParentWnd);

inline BOOL CreateManagedControl(
    typename TManagedControl^ pControl,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    int nID);
```

### <a name="parameters"></a>Parâmetros

*Ptype*<br/>
O tipo de dados do controle a ser criado. Deve ser um tipo de dados [tipo.](/dotnet/api/system.type)

*Dwstyle*<br/>
O estilo da janela para aplicar ao controle. Especifique uma combinação de estilos de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles). Atualmente, apenas os seguintes estilos são suportados: WS_TABSTOP, WS_VISIBLE, WS_DISABLED e WS_GROUP.

*Rect*<br/>
Uma [estrutura RECT](/windows/win32/api/windef/ns-windef-rect) que define as coordenadas dos cantos superior esquerdo e inferior direito do controle (apenas a primeira sobrecarga).

*nPlaceHolderID*<br/>
A alça do controle de titular de lugar estático colocado no Editor de recursos. O controle do Windows Forms recém-criado substitui o controle estático, assumindo sua posição, ordem z e estilos (apenas segunda sobrecarga).

*Pparentwnd*<br/>
Um ponteiro para a janela dos pais.

*nID*<br/>
O número de id de recurso a ser atribuído ao controle recém-criado.

*pControl*<br/>
Uma instância de um controle do Windows Forms a ser associada ao objeto [CWinFormsControl](../../mfc/reference/cwinformscontrol-class.md) (apenas quarta sobrecarga).

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna um valor não zero. Se não tiver sucesso, retorna zero.

### <a name="remarks"></a>Comentários

Este método instancia um controle .NET Framework Windows Forms em um contêiner MFC.

A primeira sobrecarga do método aceita um *pType* do tipo de dados .NET Framework para que o MFC possa instanciar um novo objeto desse tipo. *pType* deve ser um tipo de dados [tipo.](/dotnet/api/system.type)

A segunda sobrecarga do método cria um `TManagedControl` controle do Windows `CWinFormsControl` Forms com base no parâmetro modelo da classe. O tamanho e a posição do `RECT` controle baseiam-se na estrutura passada ao método. Apenas *dwStyle* importa para os estilos.

A terceira sobrecarga do método cria um controle do Windows Forms que substitui um controle estático, destruindo-o e assumindo sua posição, ordem z e estilos. O controle estático serve apenas como um espaço reservado para o controle do Windows Forms. Ao criar o controle, essa sobrecarga combina os estilos do *dwStyle* com os estilos de recurso do controle estático.

A quarta sobrecarga do método permite que você passe em um controle de Formulários do Windows já instanciado *pControl* que o MFC irá embrulhar. Deve ser do mesmo tipo `TManagedControl` que o `CWinFormsControl` parâmetro de modelo da classe.

Consulte [Usando um controle de usuário do formulário do Windows em MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md) para obter amostras sobre o uso de controles do Formulário Windows.

## <a name="cwinformscontrolcwinformscontrol"></a><a name="cwinformscontrol"></a>CWinFormsControl::CWinFormsControl

Constrói um objeto de wrapper de controle MFC Windows Forms.

```
CWinFormsControl();
```

### <a name="remarks"></a>Comentários

O controle do Windows Forms é instanciado quando você chama [CWinFormsControl::CreateManagedControl](#createmanagedcontrol).

## <a name="cwinformscontrolgetcontrol"></a><a name="getcontrol"></a>CWinFormsControl::GetControl

Recupera um ponteiro para o controle do Windows Forms.

```
inline TManagedControl^ GetControl() const;
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o controle do Windows Forms.

### <a name="example"></a>Exemplo

  Ver [CWinFormsControl::CreateManagedControl](#createmanagedcontrol).

## <a name="cwinformscontrolgetcontrolhandle"></a><a name="getcontrolhandle"></a>CWinFormsControl::GetControlHandle

Recupera uma alça para o controle do Windows Forms.

```
inline HWND GetControlHandle() const;
```

### <a name="return-value"></a>Valor retornado

Retorna uma alça para o controle do Windows Forms.

### <a name="remarks"></a>Comentários

`GetControlHandle`é um método auxiliar que retorna a alça da janela armazenada nas propriedades de controle .NET Framework. O valor da alça da janela é copiado para [CWnd::m_hWnd](../../mfc/reference/cwnd-class.md#m_hwnd) durante a chamada para [CWnd::Attach](../../mfc/reference/cwnd-class.md#attach).

## <a name="cwinformscontroloperator--gt"></a><a name="operator_-_gt"></a>CWinFormsControl::operador -&gt;

Substitui [CWinFormsControl::GetControl](#getcontrol) em expressões.

```
inline TManagedControl^  operator->() const;
```

### <a name="remarks"></a>Comentários

Este operador fornece uma sintaxe conveniente que substitui `GetControl` em expressões.

Para obter mais informações sobre o Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="cwinformscontroloperator-tmanagedcontrol"></a><a name="operator_tmanagedcontrol"></a>CWinFormsControl:operador TManagedControl^

Lança um tipo como ponteiro para um controle do Windows Forms.

```
inline operator TManagedControl^() const;
```

### <a name="remarks"></a>Comentários

Este operador `CWinFormsControl<TManagedControl>` passa para funções que aceitam um ponteiro para um controle do Windows Forms.

## <a name="see-also"></a>Confira também

[Classe CWinFormsDialog](../../mfc/reference/cwinformsdialog-class.md)<br/>
[Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)
