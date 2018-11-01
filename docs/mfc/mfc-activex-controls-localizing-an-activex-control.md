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
ms.openlocfilehash: 0a9c45873f784cf639ccf7e886f65527a6a78f2f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50613181"
---
# <a name="mfc-activex-controls-localizing-an-activex-control"></a>Controles MFC ActiveX: localizando um controle ActiveX

Este artigo aborda os procedimentos para localização de interfaces de controle ActiveX.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Se você quer adaptar um controle ActiveX para um mercado internacional, você talvez queira localizar o controle. Windows dá suporte a vários idiomas além do inglês, incluindo o alemão, francês e sueco padrão. Isso pode apresentar problemas para o controle se sua interface é apenas em inglês.

Em geral, controles ActiveX sempre devem basear sua localidade na propriedade LocaleID ambiente. Há três maneiras de fazer isso:

- Carregue os recursos sempre sob demanda, com base no valor da propriedade LocaleID ambiente atual. Exemplo de controles ActiveX MFC [LOCALIZE](../visual-cpp-samples.md) usa essa estratégia.

- Carregar recursos quando o primeiro controle seja instanciado, com base na propriedade de ambiente LocaleID e usar esses recursos para todas as outras instâncias. Este artigo demonstra essa estratégia.

    > [!NOTE]
    >  Isso não funcionará corretamente em alguns casos, se as instâncias futuras têm diferentes localidades.

- Use o `OnAmbientChanged` função de notificação para carregar dinamicamente os recursos apropriados para a localidade do contêiner.

    > [!NOTE]
    >  Isso funcionará para o controle, mas a DLL de tempo de execução será não atualizar dinamicamente seus próprios recursos quando a propriedade de ambiente LocaleID é alterado. Além disso, as DLLs de tempo de execução para controles ActiveX usam a localidade de thread para determinar a localidade para seus recursos.

O restante deste artigo descreve duas estratégias de localização. A primeira estratégia [localiza a interface de programação do controle](#_core_localizing_your_control.92.s_programmability_interface) (nomes de propriedades, métodos e eventos). A segunda estratégia [localiza a interface do usuário do controle](#_core_localizing_the_control.92.s_user_interface), usando a propriedade LocaleID de ambiente do contêiner. Para uma demonstração de localização do controle, consulte o exemplo de controles ActiveX MFC [LOCALIZE](../visual-cpp-samples.md).

##  <a name="_core_localizing_your_control.92.s_programmability_interface"></a> Localizando a Interface de programação do controle

Ao localizar a interface de programação do controle (a interface usada por programadores que criam aplicativos que usam o controle), você deve criar uma versão modificada do controle. IDL do arquivo (um script para criar a biblioteca de tipos de controle) para cada idioma que você pretende suportar. Isso é o único lugar em que você precisa localizar os nomes de propriedade do controle.

Ao desenvolver um controle localizado, inclua a ID de localidade como um atributo no nível da biblioteca de tipo. Por exemplo, se você quiser fornecer uma biblioteca de tipos com nomes de propriedade localizada francês, faça uma cópia do seu exemplo. IDL do arquivo e chamá-lo SAMPLEFR. IDL. Adicionar um atributo de ID de localidade para o arquivo (a ID de localidade para francês é 0x040c), semelhante ao seguinte:

[!code-cpp[NVC_MFC_AxLoc#1](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_1.idl)]

Altere os nomes de propriedade no SAMPLEFR. IDL para seus equivalentes em francês e, em seguida, usam o MKTYPLIB. Biblioteca, SAMPLEFR de tipos do EXE para produzir a francês. TLB.

Para criar várias bibliotecas de tipo localizado, você pode adicionar qualquer localizado. IDL arquivos ao projeto e elas serão criadas automaticamente.

#### <a name="to-add-an-idl-file-to-your-activex-control-project"></a>Para adicionar um. Arquivo IDL para seu projeto de controle ActiveX

1. Com o seu projeto de controle aberto, nos **Project** menu, clique em **Add Existing Item**.

   O **Add Existing Item** caixa de diálogo é exibida.

1. Se necessário, selecione a unidade e pasta para exibir.

1. No **arquivos do tipo** caixa, selecione **todos os arquivos (\*.\*)** .

1. Na caixa de listagem de arquivo, clique duas vezes o. Arquivo IDL que deseja inserir no projeto.

1. Clique em **abrir** quando você tiver adicionado todas as mídias necessárias. Arquivos IDL.

Porque os arquivos foram adicionados ao projeto, eles serão compilados quando o restante do projeto é compilado. As bibliotecas de tipo localizado estão localizadas no diretório do projeto atual do controle ActiveX.

Dentro de seu código, os nomes de propriedade interna (geralmente, em inglês) são sempre usados e nunca são localizados. Isso inclui o mapa de expedição de controle, as funções da troca de propriedade e seu código de troca de dados de página de propriedade.

Biblioteca de apenas um tipo (. Arquivo TLB) pode ser associado aos recursos da implementação do controle (. Arquivo OCX). Isso geralmente é a versão com o padronizado (normalmente, em inglês) nomes. Para enviar uma versão localizada do seu controle, você precisa lançar o. OCX (que já foi associado ao padrão. Versão TLB) e o. TLB para a localidade apropriada. Isso significa que somente o. OCX é necessária para versões em inglês, desde o correto. TLB já foi associado a ele. Para outras localidades, a biblioteca de tipo localizado também deve ser enviada com o. OCX.

Para garantir que os clientes do seu controle podem localizar a biblioteca de tipo localizado, registre seu específica de localidade. Arquivos TLB sob a seção de TypeLib do registro do sistema Windows. O terceiro parâmetro (normalmente opcional) da [AfxOleRegisterTypeLib](../mfc/reference/registering-ole-controls.md#afxoleregistertypelib) função é fornecida para essa finalidade. O exemplo a seguir registra uma biblioteca de tipos de francês para um controle ActiveX:

[!code-cpp[NVC_MFC_AxLoc#2](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_2.cpp)]

Quando o controle é registrado, o `AfxOleRegisterTypeLib` função procura automaticamente especificado. O arquivo TLB no mesmo diretório que o controle e registra-o no banco de dados de registro do Windows. Se o. Arquivo TLB não for encontrado, a função não tem nenhum efeito.

##  <a name="_core_localizing_the_control.92.s_user_interface"></a> Localizando a Interface do usuário do controle

Para localizar a interface do usuário do controle, coloque todos os recursos de usuário visível do controle (como páginas de propriedades e mensagens de erro) em DLLs de recurso específico do idioma. Em seguida, você pode usar propriedade LocaleID de ambiente do contêiner para selecionar a DLL apropriada para a localidade do usuário.

O exemplo de código a seguir demonstra uma abordagem para localizar e carregar a DLL de recurso para uma localidade específica. Essa função de membro chamada `GetLocalizedResourceHandle` neste exemplo, pode ser uma função de membro da sua classe de controle ActiveX:

[!code-cpp[NVC_MFC_AxLoc#3](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_3.cpp)]

Observe que a ID de subidioma pôde ser verificada em cada caso da instrução switch, para fornecer a localização mais especializada. Para ver uma demonstração dessa função, consulte a `GetResourceHandle` exemplo de controles de função no ActiveX MFC [LOCALIZE](../visual-cpp-samples.md).

Quando o controle carrega-se pela primeira vez em um contêiner, ele pode chamar [COleControl::AmbientLocaleID](../mfc/reference/colecontrol-class.md#ambientlocaleid) para recuperar a ID de localidade. O controle, em seguida, pode passar o valor de ID de localidade retornado para o `GetLocalizedResourceHandle` função, que carrega a biblioteca de recursos apropriado. O controle deve passar o identificador resultante, se houver, para [AfxSetResourceHandle](../mfc/reference/application-information-and-management.md#afxsetresourcehandle):

[!code-cpp[NVC_MFC_AxLoc#4](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_4.cpp)]

Coloque o código de exemplo acima em uma função de membro de controle, como uma substituição de [COleControl::OnSetClientSite](../mfc/reference/colecontrol-class.md#onsetclientsite). Além disso, *m_hResDLL* deve ser uma variável de membro da classe do controle.

Você pode usar uma lógica semelhante para a localização de página de propriedade um controle de. Para localizar a página de propriedades, adicione o código semelhante ao exemplo a seguir ao arquivo de implementação da sua página de propriedade (em uma substituição de [COlePropertyPage::OnSetPageSite](../mfc/reference/colepropertypage-class.md#onsetpagesite)):

[!code-cpp[NVC_MFC_AxLoc#5](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_5.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

