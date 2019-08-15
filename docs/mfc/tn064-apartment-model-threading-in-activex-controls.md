---
title: 'TN064: Threading de modelo de apartamento em controles ActiveX'
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
ms.openlocfilehash: 2c6b9dd3ed244f7169e5055eebe7a34e3345e841
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513328"
---
# <a name="tn064-apartment-model-threading-in-activex-controls"></a>TN064: Threading de modelo de apartamento em controles ActiveX

> [!NOTE]
>  A observação técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice de documentação online.

Esta nota técnica explica como habilitar o threading de modelo Apartment em um controle ActiveX. Observe que o threading de modelo Apartment tem suporte apenas nas versões C++ 4,2 ou posteriores do Visual.

## <a name="what-is-apartment-model-threading"></a>O que é Threading de modelo Apartment

O modelo de apartamento é uma abordagem para dar suporte a objetos incorporados, como controles ActiveX, em um aplicativo de contêiner multi-threaded. Embora o aplicativo possa ter vários threads, cada instância de um objeto inserido será atribuída a um "apartamento", que será executado em apenas um thread. Em outras palavras, todas as chamadas para uma instância de um controle ocorrerão no mesmo thread.

No entanto, instâncias diferentes do mesmo tipo de controle podem ser atribuídas a diferentes Apartments. Portanto, se várias instâncias de um controle compartilharem dados em comum (por exemplo, dados estáticos ou globais), o acesso a esses dados compartilhados precisará ser protegido por um objeto de sincronização, como uma seção crítica.

Para obter detalhes completos sobre o modelo de threading de apartamento, consulte [processos e threads](/windows/win32/ProcThread/processes-and-threads) na *referência do programador de OLE*.

## <a name="why-support-apartment-model-threading"></a>Por que dar suporte a Threading de modelo Apartment

Controles que oferecem suporte a Threading de modelo Apartment podem ser usados em aplicativos de contêiner multi-threaded que também dão suporte ao modelo de apartamento. Se você não habilitar o threading de modelo Apartment, limitará o possível conjunto de contêineres no qual seu controle pode ser usado.

A habilitação do Threading de modelo Apartment é fácil para a maioria dos controles, especialmente se eles tiverem pouco ou nenhum dado compartilhado.

## <a name="protecting-shared-data"></a>Protegendo dados compartilhados

Se o seu controle usa dados compartilhados, como uma variável de membro estático, o acesso a esses dados deve ser protegido com uma seção crítica para impedir que mais de um thread modifique os dados ao mesmo tempo. Para configurar uma seção crítica para essa finalidade, declare uma variável de membro estático da classe `CCriticalSection` na classe do seu controle. Use as `Lock` funções `Unlock` de membro e deste objeto de seção crítica sempre que seu código acessar os dados compartilhados.

Considere, por exemplo, uma classe de controle que precisa manter uma cadeia de caracteres que é compartilhada por todas as instâncias. Essa cadeia de caracteres pode ser mantida em uma variável de membro estático e protegida por uma seção crítica. A declaração de classe do controle conterá o seguinte:

```
class CSampleCtrl : public COleControl
{
...
    static CString _strShared;
    static CCriticalSection _critSect;
};
```

A implementação da classe incluiria definições para essas variáveis:

```
int CString CSampleCtrl::_strShared;
CCriticalSection CSampleCtrl::_critSect;
```

O acesso ao `_strShared` membro estático pode então ser protegido pela seção crítica:

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

## <a name="registering-an-apartment-model-aware-control"></a>Registrando um controle com reconhecimento de modelo de apartamento

Os controles que dão suporte ao Threading de modelo Apartment devem indicar esse recurso no registro, adicionando o valor nomeado "ThreadingModel" com um valor de "Apartment" na entrada do registro de ID de classe sob a *ID* \\  **de classe Chave InprocServer32** . Para fazer com que essa chave seja automaticamente registrada para seu controle, passe o sinalizador *afxRegApartmentThreading* no sexto parâmetro `AfxOleRegisterControlClass`para:

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

Se seu projeto de controle foi gerado pelo ControlWizard no C++ Visual versão 4,1 ou posterior, esse sinalizador já estará presente no seu código. Nenhuma alteração é necessária para registrar o modelo de Threading.

Se o projeto foi gerado por uma versão anterior do ControlWizard, o código existente terá um valor booliano como o sexto parâmetro. Se o parâmetro existente for TRUE, altere-o para *afxRegInsertable | afxRegApartmentThreading*. Se o parâmetro existente for FALSE, altere-o para *afxRegApartmentThreading*.

Se seu controle não seguir as regras para Threading de modelo Apartment, você não deve passar *afxRegApartmentThreading* nesse parâmetro.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
