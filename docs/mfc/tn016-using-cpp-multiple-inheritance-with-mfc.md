---
title: 'TN016: usando várias heranças do C++ com MFC'
ms.date: 06/28/2018
f1_keywords:
- vc.inheritance
helpviewer_keywords:
- TN016
- MI (Multiple Inheritance)
- multiple inheritance, MFC support for
ms.assetid: 4ee27ae1-1410-43a5-b111-b6af9b84535d
ms.openlocfilehash: c44639e713f6d0b26d5b74e9f645f60c8627e0c8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231761"
---
# <a name="tn016-using-c-multiple-inheritance-with-mfc"></a>TN016: usando várias heranças do C++ com MFC

Esta observação descreve como usar várias heranças (MI) com o MFC. O uso de MI não é necessário com o MFC. MI não é usado em nenhuma classe MFC e não é necessário para escrever uma biblioteca de classes.

Os subtópicos a seguir descrevem como a MI afeta o uso de idiomas comuns do MFC, além de abranger algumas das restrições de MI. Algumas dessas restrições são restrições gerais de C++. Outras são impostas pela arquitetura do MFC.

No final desta nota técnica, você encontrará um aplicativo MFC completo que usa MI.

## <a name="cruntimeclass"></a>CRuntimeClass

Os mecanismos de persistência e criação dinâmica de objetos do MFC usam a estrutura de dados [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) para identificar exclusivamente as classes. O MFC associa uma dessas estruturas a cada classe dinâmica e/ou serializável em seu aplicativo. Essas estruturas são inicializadas quando o aplicativo é iniciado usando um objeto estático especial do tipo `AFX_CLASSINIT` .

A implementação atual do `CRuntimeClass` não oferece suporte a informações de tipo de tempo de execução de mi. Isso não significa que você não pode usar MI em seu aplicativo MFC. No entanto, você terá determinadas responsabilidades quando trabalhar com objetos que têm mais de uma classe base.

O método [CObject:: IsKindOf](../mfc/reference/cobject-class.md#iskindof) não determinará corretamente o tipo de um objeto se ele tiver várias classes base. Portanto, você não pode usar [CObject](../mfc/reference/cobject-class.md) como uma classe base virtual e todas as chamadas para `CObject` funções de membro como [CObject:: Serialize](../mfc/reference/cobject-class.md#serialize) e [CObject:: operator new](../mfc/reference/cobject-class.md#operator_new) devem ter qualificadores de escopo para que o C++ possa desambiguar a chamada de função apropriada. Quando um programa usa MI no MFC, a classe que contém a `CObject` classe base precisa ser a classe mais à esquerda na lista de classes base.

Uma alternativa é usar o **`dynamic_cast`** operador. A conversão de um objeto com MI em uma de suas classes base forçará o compilador a usar as funções na classe base fornecida. Para obter mais informações, consulte [operador de dynamic_cast](../cpp/dynamic-cast-operator.md).

## <a name="cobject---the-root-of-all-classes"></a>CObject-a raiz de todas as classes

Todas as classes significativas derivam direta ou indiretamente da classe `CObject` . `CObject`Não tem nenhum dado de membro, mas tem alguma funcionalidade padrão. Ao usar a MI, você normalmente herdará de duas ou mais `CObject` classes derivadas. O exemplo a seguir ilustra como uma classe pode herdar de um [CFrameWnd](../mfc/reference/cframewnd-class.md) e um [CObList](../mfc/reference/coblist-class.md):

```cpp
class CListWnd : public CFrameWnd, public CObList
{
    // ...
};
CListWnd myListWnd;
```

Nesse caso, `CObject` é incluído duas vezes. Isso significa que você precisa de uma maneira de desambiguar qualquer referência a `CObject` métodos ou operadores. O **operador New** e o [operador Delete](../mfc/reference/cobject-class.md#operator_delete) são dois operadores que devem ser desambiguados. Como outro exemplo, o código a seguir causa um erro no tempo de compilação:

```cpp
myListWnd.Dump(afxDump); // compile time error, CFrameWnd::Dump or CObList::Dump
```

## <a name="reimplementing-cobject-methods"></a>Reimplementando métodos CObject

Quando você cria uma nova classe que tem duas ou mais `CObject` classes base derivadas, você deve reimplementar os `CObject` métodos que deseja que outras pessoas usem. Os **`new`** operadores **`delete`** são obrigatórios e o [despejo](../mfc/reference/cobject-class.md#dump) é recomendado. O exemplo a seguir reimplementa os **`new`** **`delete`** operadores e e o `Dump` método:

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

Pode parecer que, virtualmente `CObject` , a herança resolveria o problema da ambiguidade da função, mas esse não é o caso. Como não há dados de membro no `CObject` , você não precisa de herança virtual para impedir várias cópias de dados de membro de classe base. No primeiro exemplo que foi mostrado anteriormente, o `Dump` método virtual ainda é ambíguo porque ele é implementado de forma diferente no `CFrameWnd` e no `CObList` . A melhor maneira de remover a ambiguidade é seguir as recomendações apresentadas na seção anterior.

## <a name="cobjectiskindof-and-run-time-typing"></a>CObject:: IsKindOf e digitação de tempo de execução

O mecanismo de digitação de tempo de execução com suporte do MFC no `CObject` usa as macros DECLARE_DYNAMIC, IMPLEMENT_DYNAMIC, DECLARE_DYNCREATE, IMPLEMENT_DYNCREATE, DECLARE_SERIAL e IMPLEMENT_SERIAL. Essas macros podem executar uma verificação de tipo em tempo de execução para garantir downcasts seguras.

Essas macros dão suporte a apenas uma classe base e funcionarão de forma limitada para multiplicar classes herdadas. A classe base que você especifica em IMPLEMENT_DYNAMIC ou IMPLEMENT_SERIAL deve ser a primeira classe base (ou mais à esquerda). Esse posicionamento permitirá que você faça a verificação de tipo para a classe base mais à esquerda. O sistema de tipos de tempo de execução não saberá nada sobre classes base adicionais. No exemplo a seguir, os sistemas de tempo de execução farão a verificação de tipo em relação a `CFrameWnd` , mas não saberá nada sobre `CObList` .

```cpp
class CListWnd : public CFrameWnd, public CObList
{
    DECLARE_DYNAMIC(CListWnd)
    // ...
};
IMPLEMENT_DYNAMIC(CListWnd, CFrameWnd)
```

## <a name="cwnd-and-message-maps"></a>CWnd e mapas de mensagem

Para que o sistema de mapeamento de mensagens do MFC funcione corretamente, há dois requisitos adicionais:

- Deve haver apenas uma `CWnd` classe base derivada.

- A `CWnd` classe base derivada deve ser a primeira classe base (ou mais à esquerda).

Aqui estão alguns exemplos que não funcionarão:

```cpp
class CTwoWindows : public CFrameWnd, public CEdit
{ /* ... */ }; // error : two copies of CWnd

class CListEdit : public CObList, public CEdit
{ /* ... */ }; // error : CEdit (derived from CWnd) must be first
```

## <a name="a-sample-program-using-mi"></a>Um programa de exemplo usando MI

O exemplo a seguir é um aplicativo autônomo que consiste em uma classe derivada de `CFrameWnd` e [CWinApp](../mfc/reference/cwinapp-class.md). Não recomendamos que você estruture um aplicativo dessa maneira, mas este é um exemplo do menor aplicativo MFC que tem uma classe.

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

## <a name="see-also"></a>Confira também

[Notas técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Notas técnicas por categoria](../mfc/technical-notes-by-category.md)
