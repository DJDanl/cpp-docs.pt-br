---
title: 'TN064: Modelo Apartment Threading em controles ActiveX'
ms.date: 11/04/2016
f1_keywords:
- vc.controls.activex
helpviewer_keywords:
- OLE controls [MFC], container support
- containers [MFC], multithreaded
- TN064 [MFC]
- multithread container [MFC]
- apartment model threading [MFC]
ms.assetid: b2ab4c88-6954-48e2-9a74-01d4a60df073
ms.openlocfilehash: d6f02b2106693226f6380e935a54e04e10d5b4f8
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57261161"
---
# <a name="tn064-apartment-model-threading-in-activex-controls"></a>TN064: Modelo Apartment Threading em controles ActiveX

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação técnica explica como habilitar o modelo apartment threading em um controle ActiveX. Observe que modelo apartment threading só tem suporte em versões do Visual C++ 4.2 ou posteriores.

## <a name="what-is-apartment-model-threading"></a>O que é o modelo Apartment Threading

O modelo de apartment é uma abordagem para dar suporte a objetos inseridos, como controles ActiveX, dentro de um aplicativo de contêiner multithread. Embora o aplicativo pode ter vários threads, cada instância de um objeto inserido será atribuída a um "apartment," que será executada em apenas um thread. Em outras palavras, todas as chamadas em uma instância de um controle ocorrerá no mesmo thread.

No entanto, instâncias diferentes do mesmo tipo de controle podem ser atribuídas a apartments diferentes. Portanto, se várias instâncias de um controle compartilham todos os dados em comum (por exemplo, dados estáticos ou globais), acesso a esses dados compartilhados será necessário a ser protegido por um objeto de sincronização, como uma seção crítica.

Para obter detalhes completos sobre o modelo apartment threading, consulte [processos e Threads](/windows/desktop/ProcThread/processes-and-threads) na *referência do programador OLE*.

## <a name="why-support-apartment-model-threading"></a>Por que suporta o modelo Apartment Threading

Controles que dão suporte ao modelo apartment threading podem ser usados em aplicativos de contêiner multithread que também suportam o modelo de apartment. Se você não habilitar modelo-apartamento de threading, você limitará o conjunto potencial de contêineres no qual o controle pode ser usado.

Habilitar o modelo apartment threading é mais fácil para a maioria dos controles, especialmente se eles têm pouco ou nenhum dados compartilhados.

## <a name="protecting-shared-data"></a>Protegendo dados compartilhados

Se o controle usa dados compartilhados, como uma variável de membro estático, o acesso ao que os dados devem ser protegidos com uma seção crítica para impedir que mais de um thread de modificação de dados ao mesmo tempo. Para configurar uma seção crítica para essa finalidade, declare uma variável de membro estático da classe `CCriticalSection` na sua classe do controle. Use o `Lock` e `Unlock` funções de membro desta seção crítica do objeto sempre que seu código acessa os dados compartilhados.

Considere, por exemplo, uma classe de controle que precisa para manter uma cadeia de caracteres que é compartilhada por todas as instâncias. Essa cadeia de caracteres pode ser mantida em uma variável de membro estático e protegida por uma seção crítica. Declaração de classe do controle deve conter o seguinte:

```
class CSampleCtrl : public COleControl
{
...
    static CString _strShared;
    static CCriticalSection _critSect;
};
```

A implementação da classe inclui as definições para essas variáveis:

```
int CString CSampleCtrl::_strShared;
CCriticalSection CSampleCtrl::_critSect;
```

Acesso a `_strShared` membro estático, em seguida, pode ser protegido com a seção crítica:

```
void CSampleCtrl::SomeMethod()
{
    _critSect.Lock();
if (_strShared.Empty())
    _strShared = "<text>";
    _critSect.Unlock();

...
}
```

## <a name="registering-an-apartment-model-aware-control"></a>Registrar um controle de reconhecimento de modelo de Apartment

Controles que dão suporte ao modelo apartment threading devem indicar essa funcionalidade no registro, adicionando o valor nomeado "ThreadingModel" com um valor de "Apartment" na sua entrada de registro de ID de classe na *id da classe* \\ **InprocServer32** chave. Para fazer com que essa chave a ser registrado automaticamente para seu controle, passe o *afxRegApartmentThreading* sinalizador no sexto parâmetro para `AfxOleRegisterControlClass`:

```
BOOL CSampleCtrl::CSampleCtrlFactory::UpdateRegistry(BOOL bRegister)
{
    if (bRegister)
    return AfxOleRegisterControlClass(
    AfxGetInstanceHandle(),
    m_clsid,
    m_lpszProgID,
    IDS_SAMPLE,
    IDB_SAMPLE,
    afxRegApartmentThreading,
    _dwSampleOleMisc,
    _tlid,
    _wVerMajor,
    _wVerMinor);

else
    return AfxOleUnregisterClass(m_clsid,
    m_lpszProgID);

}
```

Se seu projeto de controle foi gerado pelo ControlWizard no Visual C++ versão 4.1 ou posterior, esse sinalizador já estará presente em seu código. Nenhuma alteração é necessária registrar o modelo de threading.

Se seu projeto foi gerado por uma versão anterior do ControlWizard, seu código existente terão um valor booliano como o sexto parâmetro. Se o parâmetro existente for TRUE, altere-o para *afxRegInsertable | afxRegApartmentThreading*. Se o parâmetro existente for FALSE, altere-o para *afxRegApartmentThreading*.

Se seu controle não segue as regras de modelo-apartamento de threading, você não deve passar *afxRegApartmentThreading* nesse parâmetro.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
