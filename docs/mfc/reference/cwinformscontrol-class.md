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
ms.openlocfilehash: e8728c876badcf6648740cc842a1f289789bf0f4
ms.sourcegitcommit: 975098222db3e8b297607cecaa1f504570a11799
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2018
ms.locfileid: "53178233"
---
# <a name="cwinformscontrol-class"></a>Classe CWinFormsControl

Fornece a funcionalidade básica para hospedagem de um controle dos Windows Forms.

## <a name="syntax"></a>Sintaxe

```
template<class TManagedControl>
class CWinFormsControl : public CWnd
```

#### <a name="parameters"></a>Parâmetros

*TManagedControl*<br/>
Um controle Windows Forms do .NET Framework a ser exibido no aplicativo MFC.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsControl::CWinFormsControl](#cwinformscontrol)|Constrói um objeto de wrapper do controle de formulários do Windows MFC.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsControl::CreateManagedControl](#createmanagedcontrol)|Cria um controle dos Windows Forms em um contêiner do MFC.|
|[CWinFormsControl::GetControl](#getcontrol)|Recupera um ponteiro para o controle Windows Forms.|
|[CWinFormsControl::GetControlHandle](#getcontrolhandle)|Recupera um identificador para o controle Windows Forms.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinFormsControl::operator-&gt;](#operator_-_gt)|Substitui [CWinFormsControl::GetControl](#getcontrol) em expressões.|
|[CWinFormsControl::operator TManagedControl ^](#operator_tmanagedcontrol)|Converte um tipo como um ponteiro para um controle dos Windows Forms.|

## <a name="remarks"></a>Comentários

O `CWinFormsControl` classe fornece a funcionalidade básica para hospedagem de um controle Windows Forms.

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

Seu código do MFC não armazenar em cache identificadores de janela (geralmente armazenados em `m_hWnd`). Algumas propriedades de controle de formulários do Windows exigem que o Win32 subjacente `Window` ser destruído e recriado usando `DestroyWindow` e `CreateWindow`. Os identificadores de implementação de formulários do Windows MFC a `Destroy` e `Create` eventos dos controles para atualizar o `m_hWnd` membro.

> [!NOTE]
>  Integração de formulários do Windows MFC funciona apenas em projetos que vincular dinamicamente ao MFC (no qual AFXDLL é definido).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h

##  <a name="createmanagedcontrol"></a>  CWinFormsControl::CreateManagedControl

Cria um controle dos Windows Forms em um contêiner do MFC.

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

*PDigite*<br/>
O tipo de dados do controle a ser criado. Deve ser um [tipo](https://msdn.microsoft.com/library/system.type) tipo de dados.

*dwStyle*<br/>
O estilo de janela a ser aplicado ao controle. Especifica uma combinação de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles). Atualmente, há suporte para apenas os seguintes estilos: WS_TABSTOP, WS_VISIBLE, WS_DISABLED e WS_GROUP.

*Rect*<br/>
Um [estrutura RECT](/windows/desktop/api/windef/ns-windef-tagrect) que define as coordenadas dos cantos superior esquerdo e direito inferior do controle (primeira sobrecarga apenas).

*nPlaceHolderID*<br/>
O identificador do controle local estático titular colocado no Editor de recursos. O controle de formulários do Windows criado recentemente substitui o controle estático, supondo que sua posição, ordem z e estilos (segunda sobrecarga só).

*pParentWnd*<br/>
Um ponteiro para a janela pai.

*nID*<br/>
O número de ID de recurso a ser atribuído ao controle recém-criado.

*pControl*<br/>
Uma instância de um controle de formulários do Windows a ser associada com o [CWinFormsControl](../../mfc/reference/cwinformscontrol-class.md) (somente no quarta sobrecarga) do objeto.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retorna um valor diferente de zero. Caso contrário, retornará zero.

### <a name="remarks"></a>Comentários

Esse método cria uma instância de um controle Windows Forms do .NET Framework em um contêiner do MFC.

A primeira sobrecarga do método aceita um tipo de dados do .NET Framework *PDigite* , de modo que o MFC pode instanciar um novo objeto desse tipo. *PDigite* deve ser um [tipo](https://msdn.microsoft.com/library/system.type) tipo de dados.

A segunda sobrecarga do método cria um controle de formulários do Windows com base nas `TManagedControl` parâmetro de modelo do `CWinFormsControl` classe. O tamanho e posição do controle se baseia o `RECT` estrutura é passado para o método. Somente *dwStyle* é importante para os estilos.

A terceira sobrecarga do método cria um controle de formulários do Windows que substitui um controle estático, destruí-lo e supondo que sua posição, ordem z e estilos. O controle estático serve apenas como um espaço reservado para o controle Windows Forms. Ao criar o controle, essa sobrecarga combina os estilos do *dwStyle* com estilos de recursos do controle estático.

A quarta sobrecarga do método permite que você passe em um controle de formulários do Windows já instanciado *pControl* que encapsulará o MFC. Ele deve ser do mesmo tipo que o `TManagedControl` parâmetro de modelo do `CWinFormsControl` classe.

Ver [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md) para obter exemplos sobre como usar o formulário do Windows controla.

##  <a name="cwinformscontrol"></a>  CWinFormsControl::CWinFormsControl

Constrói um objeto de wrapper do controle de formulários do Windows MFC.

```
CWinFormsControl();
```

### <a name="remarks"></a>Comentários

O controle Windows Forms é instanciado quando você chama [CWinFormsControl::CreateManagedControl](#createmanagedcontrol).

##  <a name="getcontrol"></a>  CWinFormsControl::GetControl

Recupera um ponteiro para o controle Windows Forms.

```
inline TManagedControl^ GetControl() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o controle Windows Forms.

### <a name="example"></a>Exemplo

  Ver [CWinFormsControl::CreateManagedControl](#createmanagedcontrol).

##  <a name="getcontrolhandle"></a>  CWinFormsControl::GetControlHandle

Recupera um identificador para o controle Windows Forms.

```
inline HWND GetControlHandle() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna um identificador para o controle Windows Forms.

### <a name="remarks"></a>Comentários

`GetControlHandle` é um método auxiliar que retorna o identificador de janela armazenado nas propriedades de controle do .NET Framework. O valor do identificador de janela é copiado para [CWnd::m_hWnd](../../mfc/reference/cwnd-class.md#m_hwnd) durante a chamada para [CWnd::Attach](../../mfc/reference/cwnd-class.md#attach).

##  <a name="operator_-_gt"></a>  CWinFormsControl::operator-&gt;

Substitui [CWinFormsControl::GetControl](#getcontrol) em expressões.

```
inline TManagedControl^  operator->() const;
```

### <a name="remarks"></a>Comentários

Esse operador fornece uma sintaxe conveniente que substitui `GetControl` em expressões.

Para obter mais informações sobre o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="operator_tmanagedcontrol"></a>  CWinFormsControl::operator TManagedControl ^

Converte um tipo como um ponteiro para um controle dos Windows Forms.

```
inline operator TManagedControl^() const;
```

### <a name="remarks"></a>Comentários

Este operador transfere `CWinFormsControl<TManagedControl>` para funções que aceitam um ponteiro para um controle dos Windows Forms.

## <a name="see-also"></a>Consulte também

[Classe CWinFormsDialog](../../mfc/reference/cwinformsdialog-class.md)<br/>
[Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)
