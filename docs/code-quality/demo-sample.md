---
title: Projeto de C++ de exemplo para análise de código
description: Como criar um exemplo de solução para uso na explicação do Code Analysis para o Microsoft C++ no Visual Studio.
ms.date: 04/14/2020
ms.topic: sample
helpviewer_keywords:
- demo sample [Visual Studio ALM]
- code analysis, samples
ms.assetid: 09e1b9f7-5916-4ed6-a001-5c2d7e710682
ms.openlocfilehash: dd4fe67c05200ccc2865bc7c48b1f5047d77565e
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924620"
---
# <a name="sample-c-project-for-code-analysis"></a>Projeto de C++ de exemplo para análise de código

Os procedimentos a seguir mostram como criar o exemplo para o [passo a passo: analisar o código C/C++ para defeitos](../code-quality/walkthrough-analyzing-c-cpp-code-for-defects.md). Os procedimentos criam:

- Uma solução do Visual Studio chamada *CppDemo* .

- Um projeto de biblioteca estática chamado *CodeDefects* .

- Um projeto de biblioteca estática denominado *anotações* .

Os procedimentos também fornecem o código para o cabeçalho e arquivos *.cpp* para as bibliotecas estáticas.

## <a name="create-the-cppdemo-solution-and-the-codedefects-project"></a>Criar a solução CppDemo e o projeto CodeDefects

::: moniker range=">=msvc-160"

1. Abra o Visual Studio e selecione **criar um novo projeto**

1. Na caixa de diálogo **criar um novo projeto** , altere o filtro de idioma para **C++** .

1. Selecione **Assistente de área de trabalho do Windows** e escolha o botão **Avançar** .

1. Na página **configurar seu novo projeto** , na caixa de texto **nome do projeto** , digite *CodeDefects* .

1. Na caixa de texto **nome da solução** , digite *CppDemo* .

1. Escolha **Criar** .

1. Na caixa de diálogo **projeto de área de trabalho do Windows** , altere o tipo de **aplicativo** para **biblioteca estática (. lib)** .

1. Em **Opções adicionais** , selecione **projeto vazio** .

1. Escolha **OK** para criar a solução e o projeto.

::: moniker-end

::: moniker range="msvc-150"

1. Abra o Visual Studio. Na barra de menus, escolha **arquivo**  >  **novo**  >  **projeto** .

1. Na caixa de diálogo **novo projeto** , selecione **Visual C++** > **área de trabalho do Windows** .

1. Selecione **Assistente de área de trabalho do Windows** .

1. Na caixa de texto **nome** , digite *CodeDefects* .

1. Na caixa de texto **nome da solução** , digite *CppDemo* .

1. Selecione **OK** .

1. Na caixa de diálogo **projeto de área de trabalho do Windows** , altere o tipo de **aplicativo** para **biblioteca estática (. lib)** .

1. Em **Opções adicionais** , selecione **projeto vazio** .

1. Escolha **OK** para criar a solução e o projeto.

::: moniker-end

::: moniker range="msvc-140"

1. Abra o Visual Studio. Na barra de menus, escolha **arquivo**  >  **novo**  >  **projeto** .

1. Na caixa de diálogo **novo projeto** , selecione **modelos** > **Visual C++** > **Win32** .

1. Selecione **aplicativo de console Win32** .

1. Na caixa de texto **nome** , digite *CodeDefects* .

1. Na caixa de texto **nome da solução** , digite *CppDemo* .

1. Selecione **OK** .

1. Na caixa de diálogo **Assistente de aplicativo Win32** , escolha o botão **Avançar** .

1. Altere o **tipo de aplicativo** para **biblioteca estática** .

1. Em **Opções adicionais** , desmarque o **cabeçalho pré-compilado** .

1. Escolha **concluir** para criar a solução e o projeto.

::: moniker-end

## <a name="add-the-header-and-source-file-to-the-codedefects-project"></a>Adicionar o arquivo de cabeçalho e o código-fonte ao projeto CodeDefects

1. Em Gerenciador de Soluções, expanda **CodeDefects** .

1. Clique com o botão direito do mouse para abrir o menu de contexto para **arquivos de cabeçalho** . Escolha **Adicionar**  >  **novo item** .

1. Na caixa de diálogo **Adicionar novo item** , selecione **Visual C++**  >  **código** e, em seguida, selecione **arquivo de cabeçalho (. h)** .

1. Na caixa de edição **nome** , digite *bug. h* e, em seguida, escolha o botão **Adicionar** .

1. Na janela Editar para *bug. h* , selecione e exclua o conteúdo.

1. Copie o código a seguir e cole-o no arquivo *bug. h* no editor.

    ```cpp
    #pragma once

    #include <windows.h>

    // Function prototypes
    bool CheckDomain(wchar_t const *);
    HRESULT ReadUserAccount();

    // These constants define the common sizes of the
    // user account information throughout the program
    const int USER_ACCOUNT_LEN = 256;
    const int ACCOUNT_DOMAIN_LEN = 128;
    ```

1. No Gerenciador de Soluções, clique com o botão direito do mouse para abrir o menu de contexto dos **arquivos de origem** . Escolha **Adicionar**  >  **novo item** .

1. Na caixa de diálogo **Adicionar novo item** , selecione **arquivo C++ (. cpp)** .

1. Na caixa de edição **nome** , digite *bug. cpp* e, em seguida, escolha o botão **Adicionar** .

1. Copie o código a seguir e cole-o no arquivo *bug. cpp* no editor.

    ```cpp
    #include "Bug.h"

    // the user account
    wchar_t g_userAccount[USER_ACCOUNT_LEN] = { L"domain\\user" };
    int len = 0;

    bool CheckDomain(wchar_t const* domain)
    {
        return (wcsnlen_s(domain, USER_ACCOUNT_LEN) > 0);
    }

    HRESULT ReadUserAccount()
    {
        return S_OK;
    }

    bool ProcessDomain()
    {
        wchar_t* domain = new wchar_t[ACCOUNT_DOMAIN_LEN];
        // ReadUserAccount gets a 'domain\user' input from
        //the user into the global 'g_userAccount'
        if (ReadUserAccount())
        {
            // Copies part of the string prior to the '\'
            // character onto the 'domain' buffer
            for (len = 0; (len < ACCOUNT_DOMAIN_LEN) && (g_userAccount[len] != L'\0'); len++)
            {
                if (g_userAccount[len] == L'\\')
                {
                    // Stops copying on the domain and user separator ('\')
                    break;
                }
                domain[len] = g_userAccount[len];
            }
            if ((len = ACCOUNT_DOMAIN_LEN) || (g_userAccount[len] != L'\\'))
            {
                // '\' was not found. Invalid domain\user string.
                delete[] domain;
                return false;
            }
            else
            {
                domain[len] = L'\0';
            }
            // Process domain string
            bool result = CheckDomain(domain);

            delete[] domain;
            return result;
        }
        return false;
    }

    int path_dependent(int n)
    {
        int i;
        int j;
        if (n == 0)
            i = 1;
        else
            j = 1;
        return i + j;
    }
    ```

1. Na barra de menus, escolha **arquivo**  >  **salvar tudo** .

## <a name="add-the-annotations-project-and-configure-it-as-a-static-library"></a>Adicionar o projeto Anotações e configurá-lo como uma biblioteca estática

::: moniker range=">=msvc-160"

1. Em Gerenciador de Soluções, clique com o botão direito do mouse em **CppDemo** para abrir o menu de contexto. Escolha **Adicionar**  >  **novo projeto** .

1. Na caixa de diálogo **Adicionar um novo projeto** , selecione **Assistente de área de trabalho do Windows** e, em seguida, escolha o botão **Avançar** .

1. Na página **configurar seu novo projeto** , na caixa de texto **nome do projeto** , insira *anotações* e, em seguida, escolha **criar** .

1. Na caixa de diálogo **projeto de área de trabalho do Windows** , altere o tipo de **aplicativo** para **biblioteca estática (. lib)** .

1. Em **Opções adicionais** , selecione **projeto vazio** .

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="msvc-150"

1. Em Gerenciador de Soluções, clique com o botão direito do mouse em **CppDemo** para abrir o menu de contexto. Escolha **Adicionar**  >  **novo projeto** .

1. Na caixa de diálogo **Adicionar novo projeto** , selecione **Visual C++** > **área de trabalho do Windows** .

1. Selecione **Assistente de área de trabalho do Windows** .

1. Na caixa de texto **nome** , insira *anotações* e, em seguida, escolha **OK** .

1. Na caixa de diálogo **projeto de área de trabalho do Windows** , altere o tipo de **aplicativo** para **biblioteca estática (. lib)** .

1. Em **Opções adicionais** , selecione **projeto vazio** .

1. Escolha **OK** para criar o projeto.

::: moniker-end

::: moniker range="msvc-140"

1. Em Gerenciador de Soluções, clique com o botão direito do mouse em **CppDemo** para abrir o menu de contexto. Escolha **Adicionar**  >  **novo projeto** .

1. Na caixa de diálogo **Adicionar novo projeto** , selecione **Visual C++** > **Win32** .

1. Selecione **aplicativo de console Win32** .

1. Na caixa de texto **nome** , insira *anotações* .

1. Selecione **OK** .

1. Na caixa de diálogo **Assistente de aplicativo Win32** , escolha o botão **Avançar** .

1. Altere o **tipo de aplicativo** para **biblioteca estática** .

1. Em **Opções adicionais** , desmarque o **cabeçalho pré-compilado** .

1. Escolha **concluir** para criar o projeto.

::: moniker-end

## <a name="add-the-header-file-and-source-file-to-the-annotations-project"></a>Adicionar o arquivo de cabeçalho e o arquivo de origem ao projeto Anotações

1. Em Gerenciador de Soluções, expanda **anotações** .

1. Clique com o botão direito do mouse para abrir o menu de contexto de **arquivos de cabeçalho** em **anotações** . Escolha **Adicionar**  >  **novo item** .

1. Na caixa de diálogo **Adicionar novo item** , selecione **Visual C++**  >  **código** e, em seguida, selecione **arquivo de cabeçalho (. h)** .

1. Na caixa de edição **nome** , insira *anotações. h* e, em seguida, escolha o botão **Adicionar** .

1. Na janela Editar para *anotações. h* , selecione e exclua o conteúdo.

1. Copie o código a seguir e cole-o no arquivo *Annotations. h* no editor.

    ```cpp
    #pragma once
    #include <sal.h>

    struct LinkedList
    {
        struct LinkedList* next;
        int data;
    };

    typedef struct LinkedList LinkedList;

    _Ret_maybenull_ LinkedList* AllocateNode();
    ```

1. No Gerenciador de Soluções, clique com o botão direito do mouse para abrir o menu de contexto de **arquivos de origem** em **anotações** . Escolha **Adicionar**  >  **novo item** .

1. Na caixa de diálogo **Adicionar novo item** , selecione **arquivo C++ (. cpp)** .

1. Na caixa de edição **nome** , digite *Annotations. cpp* e, em seguida, escolha o botão **Adicionar** .

1. Copie o código a seguir e cole-o no arquivo *Annotations. cpp* no editor.

    ```cpp
    #include "annotations.h"
    #include <malloc.h>

    _Ret_maybenull_ LinkedList* AllocateNode()
    {
        LinkedList* result = static_cast<LinkedList*>(malloc(sizeof(LinkedList)));
        return result;
    }

    LinkedList* AddTail(LinkedList* node, int value)
    {
        // finds the last node
        while (node->next != nullptr)
        {
            node = node->next;
        }

        // appends the new node
        LinkedList* newNode = AllocateNode();
        newNode->data = value;
        newNode->next = 0;
        node->next = newNode;

        return newNode;
    }
    ```

1. Na barra de menus, escolha **arquivo**  >  **salvar tudo** .

A solução agora está completa e deve ser compilada sem erros.

::: moniker range="msvc-150"

> [!NOTE]
> No Visual Studio 2017, você pode ver um aviso falso `E1097 unknown attribute "no_init_all"` no mecanismo do IntelliSense. Ignore esse erro.

::: moniker-end
