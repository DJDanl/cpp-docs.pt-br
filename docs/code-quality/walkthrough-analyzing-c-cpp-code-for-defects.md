---
title: 'Walkthrough: analisando CC++ /Code para defeitos'
ms.date: 11/04/2016
ms.topic: conceptual
helpviewer_keywords:
- C/C++, code analysis
- code analysis, walkthroughs
- code, analyzing C/C++
- code analysis tool, walkthroughs
ms.openlocfilehash: 5fbdf9e223b3c1e1b8664de2018381958c458f45
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77418651"
---
# <a name="walkthrough-analyzing-cc-code-for-defects"></a>Walkthrough: analisando CC++ /Code para defeitos

Este tutorial demonstra como analisar C/C++ Code para possíveis defeitos de código usando a ferramenta de análise de código para CC++ /Code.

- Execute a análise de código no código nativo.
- Analise os avisos de defeito de código.
- Trate o aviso como um erro.
- Anote o código-fonte para melhorar a análise de defeitos de código.

## <a name="prerequisites"></a>Prerequisites

- Uma cópia do [exemplo de demonstração](../code-quality/demo-sample.md).
- Noções básicas sobre C/C++.

### <a name="to-run-code-defect-analysis-on-native-code"></a>Para executar a análise de defeitos de código em código nativo

1. Abra a solução de demonstração no Visual Studio.

     A solução de demonstração agora preenche **Gerenciador de soluções**.

1. No menu **Compilar**, clique em **Recompilar Solução**.

     A solução é compilada sem erros ou avisos.

1. Em **Gerenciador de soluções**, selecione o projeto CodeDefects.

1. No menu **Projeto** , clique em **Propriedades**.

     A caixa de diálogo **páginas de propriedades do CodeDefects** é exibida.

1. Clique em **Análise de código**.

1. Clique na caixa de seleção **Habilitar análise deC++ código para C/no Build** .

1. Reconstrua o projeto CodeDefects.

     Os avisos de análise de código são exibidos no **lista de erros**.

### <a name="to-analyze-code-defect-warnings"></a>Para analisar avisos de defeito de código

1. No menu **Exibir** , clique em **Lista de Erros**.

     Dependendo do perfil de desenvolvedor que você escolheu no Visual Studio, talvez seja necessário apontar para **outras janelas** no menu **Exibir** e, em seguida, clicar em **lista de erros**.

1. No **lista de erros**, clique duas vezes no seguinte aviso:

     aviso C6230: conversão implícita entre tipos semanticamente diferentes: usando HRESULT em um contexto booliano.

     O editor de código exibe a linha que causou o aviso na função `bool ProcessDomain()`. Esse aviso indica que um `HRESULT` está sendo usado em uma instrução ' If ' onde um resultado booliano é esperado.  Normalmente, isso é um erro porque quando o `S_OK` HRESULT é retornado da função de ti indica êxito, mas quando convertido em um valor booliano, ele é avaliado como `false`.

1. Corrija esse aviso usando a macro `SUCCEEDED`, que converte em `true` quando um valor de retorno `HRESULT` indica êxito. Seu código deve ser semelhante ao seguinte código:

   ```cpp
   if (SUCCEEDED (ReadUserAccount()) )
   ```

1. No **lista de erros**, clique duas vezes no seguinte aviso:

     aviso C6282: operador incorreto: atribuição à constante no contexto de teste. Era = = pretendido?

1. Corrija esse aviso testando a igualdade. Seu código deve ser semelhante ao seguinte código:

   ```cpp
   if ((len == ACCOUNT_DOMAIN_LEN) || (g_userAccount[len] != '\\'))
   ```

### <a name="to-treat-warning-as-an-error"></a>Para tratar o aviso como um erro

1. No arquivo Bug. cpp, adicione a seguinte instrução `#pragma` ao início do arquivo para tratar o aviso C6001 como um erro:

   ```cpp
   #pragma warning (error: 6001)
   ```

1. Reconstrua o projeto CodeDefects.

     Na **lista de erros**, C6001 agora aparece como um erro.

1. Corrija os dois erros C6001 restantes na **lista de erros** inicializando `i` e `j` como 0.

1. Reconstrua o projeto CodeDefects.

     O projeto é compilado sem avisos ou erros.

### <a name="to-correct-the-source-code-annotation-warnings-in-annotationc"></a>Para corrigir os avisos de anotação de código-fonte em Annotation. c

1. Em Gerenciador de Soluções, selecione o projeto anotações.

1. No menu **Projeto** , clique em **Propriedades**.

     A caixa de diálogo **páginas de propriedades de anotações** é exibida.

1. Clique em **Análise de código**.

1. Marque a caixa de seleção **Habilitar análise deC++ código para C/no Build** .

1. Recrie o projeto de anotações.

1. No **lista de erros**, clique duas vezes no seguinte aviso:

     Aviso C6011: desreferenciando o ponteiro nulo ' newNode '.

     Esse aviso indica falha pelo chamador para verificar o valor de retorno. Nesse caso, uma chamada para **AllocateNode** pode retornar um valor nulo (consulte o arquivo de cabeçalho annotations. h para declaração de função para AllocateNode).

1. Abra o arquivo annotations. cpp.

1. Para corrigir esse aviso, use uma instrução ' If ' para testar o valor de retorno. Seu código deve ser semelhante ao seguinte código:

   ```cpp
   if (nullptr != newNode)
   {
       newNode->data = value;
       newNode->next = 0;
       node->next = newNode;
   }
   ```

1. Recrie o projeto de anotações.

     O projeto é compilado sem avisos ou erros.

### <a name="to-use-source-code-annotation"></a>Para usar a anotação de código-fonte

1. Anote os parâmetros formais e o valor de retorno da função `AddTail` para indicar que os valores de ponteiro podem ser nulos:

   ```cpp
   _Ret_maybenull_ LinkedList* AddTail(_Maybenull_ LinkedList* node, int value)
   ```

1. Recriar projeto de anotações.

1. No **lista de erros**, clique duas vezes no seguinte aviso:

     Aviso C6011: desreferenciando o ponteiro nulo ' node '.

     Esse aviso indica que o nó passado para a função pode ser nulo e indica o número da linha em que o aviso foi gerado.

1. Para corrigir esse aviso, use uma instrução ' If ' no início da função para testar o valor passado. Seu código deve ser semelhante ao seguinte código:

   ```cpp
   if (nullptr == node)
   {
        return nullptr;
   }
   ```

1. Recriar projeto de anotações.

     Agora, o projeto é compilado sem avisos ou erros.

## <a name="see-also"></a>Confira também

[Walkthrough: analisando código gerenciado para defeitos de código](/visualstudio/code-quality/walkthrough-analyzing-managed-code-for-code-defects)\
[Análise de código para C/C++](../code-quality/code-analysis-for-c-cpp-overview.md)
