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
ms.openlocfilehash: 75a6d7ea2b4f3ab229d7e3f4d411711261bb1b82
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502193"
---
# <a name="cwinformscontrol-class"></a>Classe CWinFormsControl

Fornece a funcionalidade básica para hospedagem de um controle de Windows Forms.

## <a name="syntax"></a>Sintaxe

```
template<class TManagedControl>
class CWinFormsControl : public CWnd
```

#### <a name="parameters"></a>Parâmetros

*TManagedControl*<br/>
Um controle de Windows Forms .NET Framework a ser exibido no aplicativo MFC.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsControl::CWinFormsControl](#cwinformscontrol)|Constrói um objeto de wrapper do controle MFC Windows Forms.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsControl::CreateManagedControl](#createmanagedcontrol)|Cria um controle Windows Forms em um contêiner MFC.|
|[CWinFormsControl::GetControl](#getcontrol)|Recupera um ponteiro para o controle de Windows Forms.|
|[CWinFormsControl::GetControlHandle](#getcontrolhandle)|Recupera um identificador para o controle de Windows Forms.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CWinFormsControl:: Operator&gt;](#operator_-_gt)|Substitui [CWinFormsControl:: GetControl](#getcontrol) em expressões.|
|[CWinFormsControl:: Operator TManagedControl ^](#operator_tmanagedcontrol)|Converte um tipo como um ponteiro para um controle Windows Forms.|

## <a name="remarks"></a>Comentários

A `CWinFormsControl` classe fornece a funcionalidade básica para hospedagem de um controle de Windows Forms.

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

O código MFC não deve armazenar em cache identificadores de janela `m_hWnd`(geralmente armazenados em). Algumas propriedades de controle de Windows Forms exigem que o `Window` Win32 subjacente seja destruído e recriado `DestroyWindow` usando `CreateWindow`e. O MFC Windows Forms implementação manipula os `Destroy` eventos `Create` e dos controles para atualizar o `m_hWnd` membro.

> [!NOTE]
>  A integração de Windows Forms MFC funciona apenas em projetos que vinculam dinamicamente com o MFC (no qual AFXDLL é definido).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms. h

##  <a name="createmanagedcontrol"></a>  CWinFormsControl::CreateManagedControl

Cria um controle Windows Forms em um contêiner MFC.

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

*pType*<br/>
O tipo de dados do controle a ser criado. Deve ser um tipo de dados de [tipo](/dotnet/api/system.type) .

*dwStyle*<br/>
O estilo de janela a ser aplicado ao controle. Especifique uma combinação de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles). Atualmente, há suporte apenas para os seguintes estilos: WS_TABSTOP, WS_VISIBLE, WS_DISABLED e WS_GROUP.

*rect*<br/>
Uma [estrutura RECT](/windows/win32/api/windef/ns-windef-rect) que define as coordenadas dos cantos superior esquerdo e inferior direito do controle (primeira sobrecarga somente).

*nPlaceHolderID*<br/>
O identificador do controle de suporte de local estático colocado no editor de recursos. O controle de Windows Forms recém-criado substitui o controle estático, supondo sua posição, ordem z e estilos (apenas segunda sobrecarga).

*pParentWnd*<br/>
Um ponteiro para a janela pai.

*nID*<br/>
O número de ID do recurso a ser atribuído ao controle recém-criado.

*pControl*<br/>
Uma instância de um controle de Windows Forms a ser associada ao objeto [CWinFormsControl](../../mfc/reference/cwinformscontrol-class.md) (quarta sobrecarga somente).

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará um valor diferente de zero. Se não for bem-sucedida, retornará zero.

### <a name="remarks"></a>Comentários

Esse método instancia um controle de Windows Forms .NET Framework em um contêiner MFC.

A primeira sobrecarga do método aceita um tipo de dados .NET Framework *pType* para que o MFC possa criar uma instância de um novo objeto desse tipo. *pType* deve ser um tipo de dados de [tipo](/dotnet/api/system.type) .

A segunda sobrecarga do método cria um controle de Windows Forms com base no `TManagedControl` parâmetro `CWinFormsControl` de modelo da classe. O tamanho e a posição do controle baseiam-se `RECT` na estrutura passada para o método. Somente *dwStyle* é importante para os estilos.

A terceira sobrecarga do método cria um controle de Windows Forms que substitui um controle estático, destruindo-o e supondo sua posição, ordem z e estilos. O controle estático serve apenas como um espaço reservado para o controle de Windows Forms. Ao criar o controle, essa sobrecarga combina os estilos de *dwStyle* com os estilos de recurso do controle estático.

A quarta sobrecarga do método permite que você passe um controle de Windows Forms já instanciado *pControl* que o MFC encapsulará. Ele deve ser do mesmo tipo que o `TManagedControl` parâmetro `CWinFormsControl` de modelo da classe.

Consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md) para obter exemplos sobre como usar controles de formulário do Windows.

##  <a name="cwinformscontrol"></a>CWinFormsControl::CWinFormsControl

Constrói um objeto de wrapper do controle MFC Windows Forms.

```
CWinFormsControl();
```

### <a name="remarks"></a>Comentários

O controle Windows Forms é instanciado quando você chama [CWinFormsControl:: CreateManagedControl](#createmanagedcontrol).

##  <a name="getcontrol"></a>  CWinFormsControl::GetControl

Recupera um ponteiro para o controle de Windows Forms.

```
inline TManagedControl^ GetControl() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o controle de Windows Forms.

### <a name="example"></a>Exemplo

  Consulte [CWinFormsControl:: CreateManagedControl](#createmanagedcontrol).

##  <a name="getcontrolhandle"></a>CWinFormsControl::GetControlHandle

Recupera um identificador para o controle de Windows Forms.

```
inline HWND GetControlHandle() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna um identificador para o controle de Windows Forms.

### <a name="remarks"></a>Comentários

`GetControlHandle`é um método auxiliar que retorna o identificador de janela armazenado nas propriedades do controle de .NET Framework. O valor do identificador de janela é copiado para [CWnd:: m_hWnd](../../mfc/reference/cwnd-class.md#m_hwnd) durante a chamada para [CWnd:: Attach](../../mfc/reference/cwnd-class.md#attach).

##  <a name="operator_-_gt"></a>Operador CWinFormsControl:: Operator&gt;

Substitui [CWinFormsControl:: GetControl](#getcontrol) em expressões.

```
inline TManagedControl^  operator->() const;
```

### <a name="remarks"></a>Comentários

Esse operador fornece uma sintaxe conveniente que substitui `GetControl` em expressões.

Para obter mais informações sobre Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="operator_tmanagedcontrol"></a>CWinFormsControl:: Operator TManagedControl ^

Converte um tipo como um ponteiro para um controle Windows Forms.

```
inline operator TManagedControl^() const;
```

### <a name="remarks"></a>Comentários

Esse operador passa `CWinFormsControl<TManagedControl>` para funções que aceitam um ponteiro para um controle de Windows Forms.

## <a name="see-also"></a>Consulte também

[Classe CWinFormsDialog](../../mfc/reference/cwinformsdialog-class.md)<br/>
[Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)
