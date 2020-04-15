---
title: 'Controles MFC ActiveX: localizando um controle ActiveX'
ms.date: 09/12/2018
f1_keywords:
- LocaleID
- AfxOleRegisterTypeLib
helpviewer_keywords:
- localization, ActiveX controls
- MFC ActiveX controls [MFC], localizing
- LocaleID ambient property [MFC]
- LOCALIZE sample [MFC]
ms.assetid: a44b839a-c652-4ec5-b824-04392708a5f9
ms.openlocfilehash: 987cde2117307cdb5940a31e6f01efb15c527b84
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364590"
---
# <a name="mfc-activex-controls-localizing-an-activex-control"></a>Controles MFC ActiveX: localizando um controle ActiveX

Este artigo discute procedimentos para localizar interfaces de controle ActiveX.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

Se você quiser adaptar um controle ActiveX a um mercado internacional, você pode querer localizar o controle. O Windows suporta muitos idiomas, além do inglês padrão, incluindo alemão, francês e sueco. Isso pode apresentar problemas para o controle se sua interface estiver apenas em inglês.

Em geral, os controles ActiveX devem sempre basear sua localidade na propriedade localeID ambiente. Há três modos de fazer isso:

- Carregar recursos, sempre sob demanda, com base no valor atual da propriedade localeID ambiente. A amostra de controles MFC ActiveX [LOCALIZE](../overview/visual-cpp-samples.md) usa essa estratégia.

- Carregue os recursos quando o primeiro controle for introduzido, com base na propriedade localeID ambiente, e use esses recursos para todas as outras instâncias. Este artigo demonstra essa estratégia.

    > [!NOTE]
    >  Isso não funcionará corretamente em alguns casos, se futuras instâncias tiverem locais diferentes.

- Use `OnAmbientChanged` a função de notificação para carregar dinamicamente os recursos adequados para a localização do contêiner.

    > [!NOTE]
    >  Isso funcionará para o controle, mas a DLL em tempo de execução não atualizará dinamicamente seus próprios recursos quando a propriedade localeID ambiente for mudada. Além disso, os DLLs em tempo de execução para controles ActiveX usam o local de segmento para determinar a localização de seus recursos.

O resto deste artigo descreve duas estratégias de localização. A primeira estratégia [localiza a interface de programação do controle](#_core_localizing_your_control.92.s_programmability_interface) (nomes de propriedades, métodos e eventos). A segunda estratégia [localiza a interface de usuário do controle,](#_core_localizing_the_control.92.s_user_interface)usando a propriedade LocaleID ambiente do contêiner. Para uma demonstração de localização de controle, consulte a amostra de controles MFC ActiveX [LOCALIZE](../overview/visual-cpp-samples.md).

## <a name="localizing-the-controls-programmability-interface"></a><a name="_core_localizing_your_control.92.s_programmability_interface"></a>Localização da Interface de Programação do Controle

Ao localizar a interface de programação do controle (a interface usada pelos programadores que escrevem aplicativos que usam o seu controle), você deve criar uma versão modificada do controle . Arquivo IDL (um script para construir a biblioteca do tipo de controle) para cada idioma que você pretende suportar. Este é o único lugar que você precisa para localizar os nomes da propriedade de controle.

Quando você desenvolver um controle localizado, inclua o ID local como um atributo no nível da biblioteca do tipo. Por exemplo, se você quiser fornecer uma biblioteca de tipo com nomes de propriedade localizados em francês, faça uma cópia do seu SAMPLE. Arquivo IDL, e chamá-lo SAMPLEFR. Idl. Adicione um atributo ID local ao arquivo (o ID local para francês é 0x040c), semelhante ao seguinte:

[!code-cpp[NVC_MFC_AxLoc#1](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_1.idl)]

Alterar os nomes da propriedade em SAMPLEFR. IDL para seus equivalentes franceses, e depois usar MKTYPLIB. EXE para produzir a biblioteca do tipo francês, SAMPLEFR. Tlb.

Para criar várias bibliotecas de tipos localizadas, você pode adicionar qualquer localizado . Arquivos IDL para o projeto e eles serão construídos automaticamente.

#### <a name="to-add-an-idl-file-to-your-activex-control-project"></a>Para adicionar um . Arquivo IDL para o seu projeto de controle ActiveX

1. Com seu projeto de controle aberto, no menu **Projeto,** clique em **Adicionar item existente**.

   A caixa de diálogo **Adicionar item existente** é exibida.

1. Se necessário, selecione a unidade e o diretório a serem visualizados.

1. Na caixa **Arquivos de Tipo,** selecione **Todos os arquivos (\*.\*. . .**

1. Na caixa de lista de arquivos, clique duas vezes no . Arquivo IDL que você deseja inserir no projeto.

1. Clique **em Abrir** quando tiver adicionado tudo o que for necessário . Arquivos IDL.

Como os arquivos foram adicionados ao projeto, eles serão construídos quando o resto do projeto for construído. As bibliotecas de tipo localizadas estão localizadas no diretório atual do projeto de controle ActiveX.

Dentro do seu código, os nomes de propriedade interna (geralmente em inglês) são sempre usados e nunca são localizados. Isso inclui o mapa de despacho de controle, as funções de troca de propriedades e o código de troca de dados da página de propriedade.

Apenas uma biblioteca de tipo (. O arquivo TLB) pode estar vinculado aos recursos da implementação de controle (. Arquivo OCX) Esta é geralmente a versão com os nomes padronizados (tipicamente, inglês). Para enviar uma versão localizada do seu controle você precisa enviar o . OCX (que já foi vinculado ao padrão . Versão TLB) e o . TLB para o local apropriado. Isso significa que apenas o . OCX é necessário para versões em inglês, já que o correto . TLB já foi vinculado a ele. Para outros locais, a biblioteca do tipo localizada também deve ser enviada com o . Ocx.

Para garantir que os clientes do seu controle possam encontrar a biblioteca do tipo localizada, registre sua localidade específica . Arquivos TLB na seção TypeLib do registro do sistema Windows. O terceiro parâmetro (normalmente opcional) da função [AfxOleRegisterTypeLib](../mfc/reference/registering-ole-controls.md#afxoleregistertypelib) é fornecido para este fim. O exemplo a seguir registra uma biblioteca de tipo francesa para um controle ActiveX:

[!code-cpp[NVC_MFC_AxLoc#2](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_2.cpp)]

Quando seu controle é `AfxOleRegisterTypeLib` registrado, a função procura automaticamente o especificado . Arquivo TLB no mesmo diretório que o controle e registra-o no banco de dados de registro do Windows. Se o . O arquivo TLB não é encontrado, a função não tem efeito.

## <a name="localizing-the-controls-user-interface"></a><a name="_core_localizing_the_control.92.s_user_interface"></a>Localização da interface de usuário do controle

Para localizar a interface de usuário de um controle, coloque todos os recursos visíveis do usuário do controle (como páginas de propriedade e mensagens de erro) em DLLs de recursos específicos do idioma. Em seguida, você pode usar a propriedade LocaleID ambiente do contêiner para selecionar a DLL apropriada para a localização do usuário.

O exemplo de código a seguir demonstra uma abordagem para localizar e carregar o recurso DLL para um local específico. Esta função de `GetLocalizedResourceHandle` membro, chamada para este exemplo, pode ser uma função membro da sua classe de controle ActiveX:

[!code-cpp[NVC_MFC_AxLoc#3](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_3.cpp)]

Observe que o ID de sublinguagem poderia ser verificado em cada caso da declaração do switch, para fornecer uma localização mais especializada. Para uma demonstração desta `GetResourceHandle` função, consulte a função na amostra de controles MFC ActiveX [LOCALIZE](../overview/visual-cpp-samples.md).

Quando o controle se carrega pela primeira vez em um contêiner, ele pode chamar [COleControl::AmbientLocaleID](../mfc/reference/colecontrol-class.md#ambientlocaleid) para recuperar o ID local. O controle pode então passar o valor de `GetLocalizedResourceHandle` ID local retornado para a função, que carrega a biblioteca de recursos adequada. O controle deve passar a alça resultante, se houver, para [AfxSetResourceHandle](../mfc/reference/application-information-and-management.md#afxsetresourcehandle):

[!code-cpp[NVC_MFC_AxLoc#4](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_4.cpp)]

Coloque a amostra de código acima em uma função membro do controle, como uma substituição de [COleControl::OnSetClientSite](../mfc/reference/colecontrol-class.md#onsetclientsite). Além disso, *m_hResDLL* deve ser uma variável membro da classe de controle.

Você pode usar uma lógica semelhante para localizar a página de propriedade de um controle. Para localizar a página de propriedade, adicione código semelhante à seguinte amostra ao arquivo de implementação da página de propriedade (em uma substituição de [COlePropertyPage::OnSetPageSite](../mfc/reference/colepropertypage-class.md#onsetpagesite)):

[!code-cpp[NVC_MFC_AxLoc#5](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_5.cpp)]

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
