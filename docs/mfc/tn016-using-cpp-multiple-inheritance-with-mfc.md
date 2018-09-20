---
title: 'TN016: Usando várias heranças do C++ com MFC | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.inheritance
dev_langs:
- C++
helpviewer_keywords:
- TN016
- MI (Multiple Inheritance)
- multiple inheritance, MFC support for
ms.assetid: 4ee27ae1-1410-43a5-b111-b6af9b84535d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4c0ed5c1bc73f58bec1f9ad0d6a790fe3d3c0239
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444678"
---
# <a name="tn016-using-c-multiple-inheritance-with-mfc"></a>TN016: usando várias heranças do C++ com MFC

Essa observação descreve como usar a herança múltipla (MI) com o Microsoft Foundation Classes. O uso de MI não é necessário com o MFC. MI não é usada em qualquer classe do MFC e não é necessário escrever uma biblioteca de classes.

Os seguintes subtópicos descrevem como MI afeta o uso de comuns expressões do MFC, bem como abrangendo algumas das restrições de MI. Algumas dessas restrições são restrições gerais de C++. Outros são impostos pela arquitetura MFC.

No final desta nota técnica, você encontrará um aplicativo MFC completo que usa MI.

## <a name="cruntimeclass"></a>CRuntimeClass

A persistência e mecanismos de criação de objeto dinâmico de uso MFC a [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) estrutura de dados para identificar exclusivamente as classes. MFC uma destas estruturas associa cada classe dinâmico e/ou serializável em seu aplicativo. Essas estruturas são inicializadas quando o aplicativo é iniciado usando um objeto estático especial do tipo `AFX_CLASSINIT`.

A implementação atual do `CRuntimeClass` não oferece suporte a informações de tipo de tempo de execução de MI. Isso não significa que você não pode usar para a MI em seu aplicativo do MFC. No entanto, você terá determinadas responsabilidades ao trabalhar com objetos que têm mais de uma classe base.

O [CObject::IsKindOf](../mfc/reference/cobject-class.md#iskindof) método não corretamente determinará o tipo de um objeto se ele tiver várias classes base. Portanto, é possível usar [CObject](../mfc/reference/cobject-class.md) como uma classe base virtual e todas as chamadas para `CObject` funções de membro, como [CObject::Serialize](../mfc/reference/cobject-class.md#serialize) e [denovoCObject::operator](../mfc/reference/cobject-class.md#operator_new)deve ter qualificadores de escopo para que esse C++ pode resolver a ambiguidade da chamada de função apropriada. Quando um programa usa MI dentro do MFC, a classe que contém o `CObject` classe base precisa ser a classe mais à esquerda na lista de classes base.

Uma alternativa é usar o `dynamic_cast` operador. Converter um objeto com para a MI para uma de suas classes base será forçar o compilador a usar as funções na classe base fornecido. Para obter mais informações, consulte [operador dynamic_cast](../cpp/dynamic-cast-operator.md).

## <a name="cobject---the-root-of-all-classes"></a>CObject - raiz de todas as Classes

Todas as classes significativas derivam direta ou indiretamente da classe `CObject`. `CObject` faz não tem nenhum dado de membro, mas tem algumas funcionalidades padrão. Quando você usa para a MI, você normalmente herdam de dois ou mais `CObject`-as classes derivadas. O exemplo a seguir ilustra como uma classe pode herdar de uma [CFrameWnd](../mfc/reference/cframewnd-class.md) e uma [CObList](../mfc/reference/coblist-class.md):

```cpp
class CListWnd : public CFrameWnd, public CObList
{
    // ...
};
CListWnd myListWnd;
```

Nesse caso, `CObject` é incluída duas vezes. Isso significa que você precisa de uma maneira de resolver a ambiguidade de qualquer referência a `CObject` métodos ou operadores. O **operador new** e [operador delete](../mfc/reference/cobject-class.md#operator_delete) são dois operadores que devem ser sem ambiguidade. Como outro exemplo, o código a seguir causa um erro em tempo de compilação:

```cpp
myListWnd.Dump(afxDump); // compile time error, CFrameWnd::Dump or CObList::Dump
```

## <a name="reimplementing-cobject-methods"></a>Reimplementação de métodos de CObject

Quando você cria uma nova classe que tenha duas ou mais `CObject` derivadas de classes base, você deve reimplementar a `CObject` métodos que você deseja que outras pessoas usem. Operadores **novos** e **excluir** são obrigatórios e [despejar](../mfc/reference/cobject-class.md#dump) é recomendado. Os reimplements de exemplo a seguir a **novos** e **excluir** operadores e o `Dump` método:

```cpp
class CListWnd : public CFrameWnd, public CObList
{
public:
    void* operator new(size_t nSize)
    {
        return CFrameWnd:: operator new(nSize);
    }
    void operator delete(void* p)
    {
        CFrameWnd:: operator delete(p);
    }
    void Dump(CDumpContent& dc)
    {
        CFrameWnd::Dump(dc);
        CObList::Dump(dc);
    }
    // ...
};
```

## <a name="virtual-inheritance-of-cobject"></a>Herança virtual de CObject

Pode parecer que praticamente herdando `CObject` resolveria o problema de ambiguidade de função, mas esse não for o caso. Porque não há nenhum dado de membro em `CObject`, você não precisa de herança virtual para impedir que várias cópias de uma classe base de dados de membros. No primeiro exemplo mostrado anteriormente, o `Dump` método virtual é ainda ambíguo porque ela é implementada de forma diferente em `CFrameWnd` e `CObList`. A melhor maneira de remover a ambiguidade é seguir as recomendações apresentadas na seção anterior.

## <a name="cobjectiskindof-and-run-time-typing"></a>CObject::IsKindOf e tempo de execução digitando

O mecanismo de digitação de tempo de execução com suporte pelo MFC em `CObject` usa as macros DECLARE_DYNAMIC, IMPLEMENT_DYNAMIC, DECLARE_DYNCREATE, IMPLEMENT_DYNCREATE, DECLARE_SERIAL e IMPLEMENT_SERIAL. Essas macros podem executar uma verificação de tipo de tempo de execução para garantir a segurança downcasts.

Essas macros dar suporte a apenas uma única classe base e funcionarão de forma limitada para classes herdadas multiply. A classe base que você especifica em IMPLEMENT_DYNAMIC ou IMPLEMENT_SERIAL deve ser a classe base primeira (ou mais à esquerda). Esse posicionamento permite para o tipo de verificação para a classe base mais à esquerda só. O sistema de tipo de tempo de execução será saber nada sobre classes base adicionais. No exemplo a seguir, os sistemas de tempo de execução fará a verificação em relação de tipo `CFrameWnd`, mas será saber nada sobre `CObList`.

```cpp
class CListWnd : public CFrameWnd, public CObList
{
    DECLARE_DYNAMIC(CListWnd)
    // ...
};
IMPLEMENT_DYNAMIC(CListWnd, CFrameWnd)
```

## <a name="cwnd-and-message-maps"></a>CWnd e mapas de mensagem

Para o sistema de mapa de mensagem do MFC funcionar corretamente, há dois requisitos adicionais:

- Deve haver apenas um `CWnd`-derivado da classe base.

- O `CWnd`-classe base derivada deve ser a classe base primeira (ou mais à esquerda).

Aqui estão alguns exemplos que não funcionará:

```cpp
class CTwoWindows : public CFrameWnd, public CEdit
{ /* ... */ }; // error : two copies of CWnd

class CListEdit : public CObList, public CEdit
{ /* ... */ }; // error : CEdit (derived from CWnd) must be first
```

## <a name="a-sample-program-using-mi"></a>Um programa de exemplo usando MI

O exemplo a seguir é um aplicativo autônomo que consiste em uma classe derivada de `CFrameWnd` e [CWinApp](../mfc/reference/cwinapp-class.md). Não recomendamos que você estruturar um aplicativo dessa maneira, mas isso é um exemplo de aplicativo do MFC menor que tem uma classe.

```cpp
#include <afxwin.h>

class CHelloAppAndFrame : public CFrameWnd, public CWinApp
{
public:
    CHelloAppAndFrame() {}

    // Necessary because of MI disambiguity
    void* operator new(size_t nSize)
        { return CFrameWnd::operator new(nSize); }
    void operator delete(void* p)
        { CFrameWnd::operator delete(p); }

    // Implementation
    // CWinApp overrides
    virtual BOOL InitInstance();
    // CFrameWnd overrides
    virtual void PostNcDestroy();
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CHelloAppAndFrame, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

// because the frame window is not allocated on the heap, we must
// override PostNCDestroy not to delete the frame object
void CHelloAppAndFrame::PostNcDestroy()
{
    // do nothing (do not call base class)
}

void CHelloAppAndFrame::OnPaint()
{
    CPaintDC dc(this);
    CRect rect;
    GetClientRect(rect);

    CString s = "Hello, Windows!";
    dc.SetTextAlign(TA_BASELINE | TA_CENTER);
    dc.SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
    dc.SetBkMode(TRANSPARENT);
    dc.TextOut(rect.right / 2, rect.bottom / 2, s);
}

// Application initialization
BOOL CHelloAppAndFrame::InitInstance()
{
    // first create the main frame
    if (!CFrameWnd::Create(NULL, "Multiple Inheritance Sample",
        WS_OVERLAPPEDWINDOW, rectDefault))
        return FALSE;

    // the application object is also a frame window
    m_pMainWnd = this;
    ShowWindow(m_nCmdShow);
    return TRUE;
}

CHelloAppAndFrame theHelloAppAndFrame;
```

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
