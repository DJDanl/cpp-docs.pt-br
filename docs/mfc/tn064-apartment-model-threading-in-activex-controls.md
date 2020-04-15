---
title: 'TN064: modelo Apartment Threading em controles ActiveX'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE controls [MFC], container support
- containers [MFC], multithreaded
- TN064 [MFC]
- multithread container [MFC]
- apartment model threading [MFC]
ms.assetid: b2ab4c88-6954-48e2-9a74-01d4a60df073
ms.openlocfilehash: 0c6a42124b4b2b03ae7cd9277fa14d43eac7a2bb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366063"
---
# <a name="tn064-apartment-model-threading-in-activex-controls"></a>TN064: modelo Apartment Threading em controles ActiveX

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota técnica explica como ativar a threading do modelo de apartamento em um controle ActiveX. Observe que a rosca do modelo de apartamento só é suportada nas versões Visual C++ 4.2 ou posterior.

## <a name="what-is-apartment-model-threading"></a>O que é threading apartamento-modelo

O modelo de apartamento é uma abordagem para suportar objetos incorporados, como controles ActiveX, dentro de uma aplicação de contêiner multithreaded. Embora o aplicativo possa ter vários threads, cada instância de um objeto incorporado será atribuída a um "apartamento", que será executado em apenas um segmento. Em outras palavras, todas as chamadas para uma instância de um controle acontecerão no mesmo segmento.

No entanto, diferentes instâncias do mesmo tipo de controle podem ser atribuídas a apartamentos diferentes. Assim, se várias instâncias de um controle compartilharem qualquer dado em comum (por exemplo, dados estáticos ou globais), então o acesso a esses dados compartilhados precisará ser protegido por um objeto de sincronização, como uma seção crítica.

Para obter detalhes completos sobre o modelo de rosca do apartamento, consulte [Processos e Threads](/windows/win32/ProcThread/processes-and-threads) na *Referência do Programador OLE*.

## <a name="why-support-apartment-model-threading"></a>Por que apoiar a threading do modelo de apartamento

Controles que suportam threading modelo de apartamento podem ser usados em aplicativos de contêineres multithreaded que também suportam o modelo de apartamento. Se você não habilitar a rosca do modelo de apartamento, você limitará o conjunto potencial de contêineres nos quais seu controle pode ser usado.

Habilitar a rosca do modelo de apartamento é fácil para a maioria dos controles, especialmente se eles têm pouco ou nenhum dado compartilhado.

## <a name="protecting-shared-data"></a>Proteção de dados compartilhados

Se o seu controle usar dados compartilhados, como uma variável de membro estático, o acesso a esses dados deve ser protegido com uma seção crítica para evitar que mais de um segmento modifique os dados ao mesmo tempo. Para configurar uma seção crítica para este fim, `CCriticalSection` declare uma variável de classe de membro estático na classe do seu controle. Use `Lock` as `Unlock` funções e o membro deste objeto de seção crítica onde seu código acessar os dados compartilhados.

Considere, por exemplo, uma classe de controle que precisa manter uma string que é compartilhada por todas as instâncias. Esta seqüência pode ser mantida em uma variável de membro estático e protegida por uma seção crítica. A declaração de classe do controle conteria o seguinte:

```cpp
class CSampleCtrl : public COleControl
{
...
    static CString _strShared;
    static CCriticalSection _critSect;
};
```

A implementação para a classe incluiria definições para essas variáveis:

```cpp
int CString CSampleCtrl::_strShared;
CCriticalSection CSampleCtrl::_critSect;
```

O acesso `_strShared` ao membro estático pode então ser protegido pela seção crítica:

```cpp
void CSampleCtrl::SomeMethod()
{
    _critSect.Lock();
if (_strShared.Empty())
    _strShared = "<text>";
    _critSect.Unlock();

...
}
```

## <a name="registering-an-apartment-model-aware-control"></a>Registrando um controle de reconhecimento de modelo de apartamento

Os controles que suportam a threadagem do modelo de apartamento devem indicar esse recurso no registro, adicionando o valor chamado "ThreadingModel" com um valor de "Apartamento" em sua entrada de registro de ID de classe sob a chave *id*\\**classe InprocServer32.** Para que essa chave seja registrada automaticamente para o seu controle, passe o sinalizador `AfxOleRegisterControlClass` *afxRegApartmentThreading* no sexto parâmetro para:

```cpp
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

Se o seu projeto de controle foi gerado pelo ControlWizard na versão 4.1 do Visual C++ ou posterior, esse sinalizador já estará presente no seu código. Não são necessárias alterações para registrar o modelo de rosca.

Se o seu projeto foi gerado por uma versão anterior do ControlWizard, seu código existente terá um valor booleano como o sexto parâmetro. Se o parâmetro existente for TRUE, altere-o para *afxRegInsertable | afxRegApartmentThreading*. Se o parâmetro existente for FALSO, altere-o para *afxRegApartmentThreading*.

Se o seu controle não seguir as regras para threading modelo de apartamento, você não deve passar *afxRegApartmentThreading* neste parâmetro.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
