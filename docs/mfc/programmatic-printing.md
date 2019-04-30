---
title: Impressão programática
ms.date: 11/04/2016
helpviewer_keywords:
- printing [MFC], active documents
- active documents [MFC], printing
- printing [MFC], programmatic
- IPrint interface
- printing [MFC]
ms.assetid: 3db0945b-5e13-4be4-86a0-6aecdae565bd
ms.openlocfilehash: eb8804610832f91f4b24487fddfe9c24a3799117
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64342089"
---
# <a name="programmatic-printing"></a>Impressão programática

OLE forneciam os meios para identificar exclusivamente os documentos persistentes (`GetClassFile`) e carregá-los em seu código associado (`CoCreateInstance`, `QueryInterface(IID_IPersistFile)`, `QueryInterface(IID_IPersistStorage)`, `IPersistFile::Load`, e `IPersistStorage::Load`). Para habilitar a impressão de documentos ainda mais, contenção de documentos ativos (usando um design OLE existente não acompanham originalmente OLE 2.0) apresenta uma interface de padrão da Base de dados de impressão, `IPrint`, disponível por meio de qualquer objeto que pode carregar o estado persistente do tipo de documento. Cada modo de exibição de um documento ativo, opcionalmente, pode dar suporte a `IPrint` interface para fornecer esses recursos.

O `IPrint` interface é definida da seguinte maneira:

```
interface IPrint : IUnknown
    {
    HRESULT SetInitialPageNum([in] LONG nFirstPage);
    HRESULT GetPageInfo(
        [out] LONG *pnFirstPage,
        [out] LONG *pcPages);
    HRESULT Print(
        [in] DWORD grfFlags,
        [in,out] DVTARGETDEVICE **pptd,
        [in,out] PAGESET ** ppPageSet,
        [in,out] STGMEDIUM **ppstgmOptions,
        [in] IContinueCallback* pCallback,
        [in] LONG nFirstPage,
        [out] LONG *pcPagesPrinted,
        [out] LONG *pnPageLast);
    };
```

Os clientes e os contêineres simplesmente usam `IPrint::Print` para instruir o documento para imprimir em si, quando esse documento é carregado, especificar sinalizadores de controle de impressão, o dispositivo de destino, as páginas a serem impressas e opções adicionais. O cliente também pode controlar a continuação de impressão por meio da interface `IContinueCallback` (veja abaixo).

Além disso, `IPrint::SetInitialPageNum` suporta a capacidade de imprimir uma série de documentos, como um numerando perfeitamente, páginas, obviamente, um benefício para os contêineres de documento ativo como o Office Binder. `IPrint::GetPageInfo` torna exibindo informações de paginação simples, permitindo que o chamador recuperar o início página número anteriormente passado para `SetInitialPageNum` (ou padrão interna do documento, número da página inicial) e o número de páginas no documento.

Objetos que dão suporte ao `IPrint` são marcados no registro com a chave "Cálculo" armazenada sob o CLSID do objeto:

HKEY_CLASSES_ROOT\CLSID\\{...}\Printable

`IPrint` geralmente é implementado no mesmo objeto que suporta qualquer `IPersistFile` ou `IPersistStorage`. Os chamadores Observe a capacidade de imprimir o estado persistente de alguma classe, de forma programática, examinando o registro para a chave "Cálculo". Atualmente, "Imprimível" indica que há suporte pelo menos `IPrint`; outras interfaces podem ser definidos no futuro que estariam disponível por meio `QueryInterface` onde `IPrint` simplesmente representa o nível de base de suporte.

Durante um procedimento de impressão, talvez você queira o cliente ou o contêiner que iniciou a impressão para controlar ou não a impressão deve continuar. Por exemplo, o contêiner pode dar suporte a um comando "Parar Print" que deve terminar o trabalho de impressão assim que possível. Para dar suporte a esse recurso, o cliente de um objeto imprimível pode implementar um objeto de coletor pequena notificação com a interface `IContinueCallback`:

```
interface IContinueCallback : IUnknown
    {
    HRESULT FContinue(void);
    HRESULT FContinuePrinting(
        [in] LONG cPagesPrinted,
        [in] LONG nCurrentPage,
        [in] LPOLESTR pszPrintStatus);
    };
```

Essa interface foi projetada para ser útil como uma função de retorno de chamada de continuação genérico que ocupa o lugar de vários procedimentos de continuação na API do Win32 (como o `AbortProc` para impressão e o `EnumMetafileProc` para enumeração de metarquivo). Assim, esse design de interface é útil em uma ampla variedade de processos demorados.

Nos casos mais genéricos, o `IContinueCallback::FContinue` função é chamada periodicamente por qualquer processo demorado. O objeto coletor Retorna S_OK para continuar a operação e S_FALSE para impedir que o procedimento assim que possível.

`FContinue`, no entanto, não é usado no contexto de `IPrint::Print`; em vez disso, imprimindo usa `IContinueCallback::FContinuePrint`. Qualquer objeto de impressão deve chamar periodicamente `FContinuePrinting` passando uma cadeia de caracteres adicional que descreve o status de impressão que o cliente pode optar por exibir para o usuário (como "página, o número da página que está sendo impresso e o número de páginas imprimindo 5 de 19").

## <a name="see-also"></a>Consulte também

[Contêineres de documento ativos](../mfc/active-document-containers.md)
